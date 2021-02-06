#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    const int INF = 1001001001;
    vector<vector<int>> g(2*n);
    vector<vector<int>> cost(2*n, vector<int>(2*n, INF));
    rep(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        g[a].push_back(b);
        g[n+a].push_back(b);
        cost[a][b] = min(cost[a][b], c);
        cost[n+a][b] = min(cost[n+a][b], c);
    }

    vector<int> dist(2*n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    rep(i, n){
        dist.assign(2*n, INF);
        pq.push({0, n+i});
        dist[i+n] = 0;

        while(!pq.empty()){
            pair<int, int> p = pq.top();
            pq.pop();
            int v = p.second;

            for(int nv: g[v]){
                if(dist[nv] > dist[v] + cost[v][nv]){
                    dist[nv] = dist[v] + cost[v][nv];
                    pq.push({dist[nv], nv});
                }
            }
        }

        if(dist[i] == INF) cout << -1 << endl;
        else cout << dist[i] << endl;
        
    }

    return 0;
}