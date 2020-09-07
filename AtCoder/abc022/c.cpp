#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> g(n+1);
    const int INF = 1001001001;
    vector<vector<int>> cost(n+1, vector<int>(n+1, INF));
    for(int i = 0; i < m; ++i){
        int u, v, l;
        cin >> u >> v >> l;
        --u;
        --v;

        g[u].push_back(v);
        g[v].push_back(u);
        cost[u][v] = l;
        cost[v][u] = l;

        if(u == 0){
            g[n].push_back(v);
            g[v].push_back(n);
            cost[n][v] = l;
            cost[v][n] = l;
        }
    }
    
    int res = INF;
    for(int st: g[0]){
        vector<int> dist(n+1, INF);
        dist[st] = cost[0][st];

        vector<vector<int>> c = cost;
        c[st][0] = INF;
        c[st][n] = INF;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({dist[st], st});

        while(!pq.empty()){
            int v = pq.top().second;
            pq.pop();

            for(int nv: g[v]){
                if(dist[nv] > dist[v] + c[v][nv]){
                    dist[nv] = dist[v] + c[v][nv];
                    pq.push({dist[nv], nv});
                }
            }
        }

        res = min(res, dist[n]);

    }

    if(res >= INF) cout << -1 << endl;
    else cout << res << endl;


    return 0;
}
