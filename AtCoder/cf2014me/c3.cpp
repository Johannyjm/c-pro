#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> g, cost;
const int INF = 1001001001;

vector<int> dijkstra(int st){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, st});
    vector<int> dist(n, INF);
    dist[st] = 0;
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

    return dist;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    int s, t;
    cin >> s >> t;
    --s;
    --t;
    g.resize(n);
    cost.resize(n, vector<int>(n, INF));
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

    vector<int> dist1 = dijkstra(s);
    vector<int> dist2 = dijkstra(t);
    
    for(int i = 0; i < n; ++i){
        if(dist1[i]==INF || dist2[i]==INF) continue;
        if(dist1[i] == dist2[i]){
            cout << i+1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
