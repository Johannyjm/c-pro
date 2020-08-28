#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int s, t;
    cin >> s >> t;
    --s;
    --t;

    const int INF = 1001001001;
    vector<vector<int>> g(n), cost(n, vector<int>(n, INF));
    for(int i = 0; i < m; ++i){
        int x, y, d;
        cin >> x >> y >> d;
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
        cost[x][y] = d;
        cost[y][x] = d;
    }
    
    for(int u = 0; u < n; ++u){
        if(u==s || u==t) continue;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, u});
        vector<int> dist(n, INF);
        dist[u] = 0;
        while(!pq.empty()){
            int v = pq.top().second;
            pq.pop();

            for(int nv: g[v]){
                if(dist[nv] > dist[v] + cost[v][nv]){
                    dist[nv] = dist[v] + cost[v][nv];
                    pq.push({dist[nv], nv});
                }
            }
        }

        if(dist[s]==INF || dist[t]==INF) continue;
        if(dist[s] == dist[t]){
            cout << u+1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
