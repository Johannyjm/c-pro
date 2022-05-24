#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

struct Edge{
    int to;
    ll weight;
    int idx;

    Edge(int t, ll w, int i): to(t), weight(w), idx(i) {}
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

        --a;
        --b;
        g[a].push_back(Edge(b, c, i));
        g[b].push_back(Edge(a, c, i));
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 0});

    const ll INF = 1ll << 60;
    vector<ll> dist(n, INF);
    dist[0] = 0;
    vector<int> prev(n, -1);

    while(!pq.empty()){
        auto [d, v] = pq.top();
        pq.pop();

        if(dist[v] != d) continue;
        
        for(auto ne: g[v]){
            int nv = ne.to;

            if(dist[nv] > dist[v] + ne.weight){
                dist[nv] = dist[v] + ne.weight;

                pq.push({dist[nv], nv});

                prev[nv] = ne.idx;
            }
        }
    }

    set<int> res;
    for(auto i: prev){
        if(i != -1) res.insert(i);
    }

    for(auto i: res) cout << i+1 << " ";
    cout << endl;    

    return 0;
}