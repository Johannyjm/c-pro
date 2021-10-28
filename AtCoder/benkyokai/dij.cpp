#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
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
    rep(i, m){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        g[a].push_back(Edge(b, c));
        g[b].push_back(Edge(a, c));
    }

    const ll INF = 1ll << 60;
    vector<ll> dist(n, INF);
    dist[0] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 0});

    while(!pq.empty()){
        auto [d, v] = pq.top();

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