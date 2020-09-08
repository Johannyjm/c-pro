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

    const int INF = 1001001001;
    vector<vector<int>> g(n);
    vector<vector<int>> cost(n, vector<int>(n, INF));

    rep(_, k){
        int cmd;
        cin >> cmd;
        if(cmd == 1){
            int c, d, e;
            cin >> c >> d >> e;
            --c;
            --d;

            g[c].push_back(d);
            g[d].push_back(c);

            cost[c][d] = min(cost[c][d], e);
            cost[d][c] = min(cost[d][c], e);
        }

        else{
            int a, b;
            cin >> a >> b;
            --a;
            --b;

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push(make_pair(0, a));

            vector<int> dist(n, INF);
            dist[a] = 0;

            while(!pq.empty()){
                pair<int, int> p = pq.top();
                pq.pop();
                int v = p.second;

                for(int nv: g[v]){
                    if(dist[v] + cost[v][nv] < dist[nv]){
                        dist[nv] = dist[v] + cost[v][nv];
                        pq.push(make_pair(dist[nv], nv));
                    }
                }
            }

            if(dist[b] == INF) cout << -1 << endl;
            else cout << dist[b] << endl;
        }
    }

    return 0;
}