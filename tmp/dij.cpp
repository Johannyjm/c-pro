#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

struct Edge{
    int to;
    ll weight;

    Edge(int t, ll w): to(t), weight(w) {}
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> g(n);
    for(int i = 0; i < m; ++i){
        int a, b;
        ll c;
        cin >> a >> b >> c;

        --a;
        --b;
        g[a].push_back(Edge(b, c));
        g[b].push_back(Edge(a, c));
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 0});

    const ll INF = 1ll << 60;
    vector<ll> dist(n, INF);
    dist[0] = 0;

    while(!pq.empty()){
        auto [d, v] = pq.top();
        pq.pop();

        if(dist[v] != d) continue;

        for(auto ne: g[v]){
            int nv = ne.to;

            if(dist[nv] > dist[v] + ne.weight){
                dist[nv] = dist[v] + ne.weight;

                pq.push({dist[nv], nv});
            }
        }
    }

    ll res = dist[n-1];

    if(res == INF) res = -1;

    cout << res << endl;
    
    return 0;
}
