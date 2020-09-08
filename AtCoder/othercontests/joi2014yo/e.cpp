#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> c(n), r(n);
    rep(i, n) cin >> c[i] >> r[i];

    vector<vector<int>> g(n); // for bfs
    rep(_, k){
        int a, b;
        cin >> a >> b;
        --a;
        --b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<vector<int>> gg(n); // for dijkstra

    const int INF = 1001001001;
    vector<vector<int>> cost(n, vector<int>(n, INF));
    rep(sv, n){

        vector<int> dist(n, INF);
        dist[sv] = 0;
        queue<int> q;
        q.push(sv);

        bool flg = false;
        while(!q.empty()){
            int v = q.front();
            q.pop();

            for(int nv: g[v]){
                if(dist[nv] != INF) continue;

                dist[nv] = dist[v] + 1;
                q.push(nv);

                if(dist[nv] <= r[sv]) {
                    cost[sv][nv] = c[sv];
                    gg[sv].push_back(nv); // directed graph
                }
                else{
                    flg = true;
                    break;
                }
            }

            if(flg) break;
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, 0));
    vector<int> dist(n, INF);
    dist[0] = 0;

    while(!pq.empty()){
        pair<int, int> p = pq.top();
        pq.pop();
        int v = p.second;

        for(int nv: gg[v]){
            if(dist[v] + cost[v][nv] < dist[nv]){
                dist[nv] = dist[v] + cost[v][nv];
                pq.push(make_pair(dist[nv], nv));
            }
        }
    }

    cout << dist[n-1] << endl;

    return 0;
}