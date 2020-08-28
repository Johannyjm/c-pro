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

    if(m == 1){
        cout << -1 << endl;
        return 0;
    }

    vector<vector<int>> g(n);
    const int INF = 1001001001;
    vector<vector<int>> cost(n, vector<int>(n, INF));
    for(int i = 0; i < n; ++i){
        int x, y, d;
        cin >> x >> y >> d;
        --x;
        --y;
        if((x==s&&y==t) || (x==t&&y==s)) continue;
        g[x].push_back(y);
        g[y].push_back(x);
        cost[x][y] = d;
        cost[y][x] = d;
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    vector<int> dist(n, INF);
    vector<vector<int>> prev(n);
    dist[s] = 0;
    prev[s].push_back(-1);
    
    while(!pq.empty()){
        int v = pq.top().second;
        pq.pop();

        for(int nv: g[v]){
            if(dist[nv] == dist[v] + cost[v][nv]){
                prev[nv].push_back(v);
            }
            if(dist[nv] > dist[v] + cost[v][nv]){
                dist[nv] = dist[v] + cost[v][nv];
                pq.push({dist[nv], nv});
                prev[nv].push_back(v);
            }
        }
    }
    
    for(int i = 0; i < n; ++i){
        if(dist[i] * 2 == dist[t]){
            cout << i+1 << endl;
            return 0;
        }
    }
    
    cout << -1 << endl;

    return 0;
}
