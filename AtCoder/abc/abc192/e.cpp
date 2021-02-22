#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;
const ll INF = 1ll<<60;

struct Edge{
    int to;
    int weight;
    int k;
    Edge(int t, int w, int k): to(t), weight(w), k(k) {}
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, x, y;
    cin >> n >> m >> x >> y;
    --x;
    --y;
    
    vector<vector<Edge>> g(n);

    for(int i = 0; i < m; ++i){
        int a, b, t, k;
        cin >> a >> b >> t >> k;
        --a;
        --b;
        g[a].push_back(Edge(b, t, k));
        g[b].push_back(Edge(a, t, k));
    }

    vector<ll> dist(n, INF);
    dist[x] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, x});

    while(!pq.empty()){
        pair<ll, int> p = pq.top();
        pq.pop();
        int v = p.second;

        if(v == y) break;

        for(auto ne: g[v]){
            ll ndist = ((dist[v] + ne.k - 1) / ne.k) * ne.k;
            // if(ndist % ne.k != 0) ndist += ne.k - ndist%ne.k;
            ndist += ne.weight;

            if(ndist < dist[ne.to]){
                dist[ne.to] = ndist;
                pq.push({dist[ne.to], ne.to});
            }
        }
    }

    if(dist[y] == INF) cout << -1 << endl;
    else cout << dist[y] << endl;

//    cout << endl;

//    for(auto e: dist) cout << e << " ";
//    cout << endl;

    return 0;
}
