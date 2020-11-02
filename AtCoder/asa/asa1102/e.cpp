#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

struct Edge{
    int to;
    int weight;
    Edge(int t, int w): to(t), weight(w) {}
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m, t;
    cin >> n >> m >> t;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<vector<Edge>> g(n), gr(n);
    rep(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;

        g[a].push_back(Edge(b, c));
        gr[b].push_back(Edge(a, c));
    }

    const ll INF = 1ll<<60;
    vector<ll> dist(n, INF);
    dist[0] = 0;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 0});

    while(!pq.empty()){
        pair<ll, ll> p = pq.top();
        pq.pop();
        int v = p.second;

        for(auto ne: g[v]){
            if(dist[ne.to] > dist[v] + ne.weight){
                dist[ne.to] = dist[v] + ne.weight;

                pq.push({dist[ne.to], ne.to});
            }
        }
    }

    vector<ll> distr(n, INF);
    distr[0] = 0;

    pq.push({0, 0});

    while(!pq.empty()){
        pair<ll, ll> p = pq.top();
        pq.pop();
        int v = p.second;

        for(auto ne: gr[v]){
            if(distr[ne.to] > distr[v] + ne.weight){
                distr[ne.to] = distr[v] + ne.weight;

                pq.push({distr[ne.to], ne.to});
            }
        }
    }

    // for(auto e: dist) cout << e << " ";
    // cout << endl;
    // for(auto e: distr) cout << e << " ";
    // cout << endl;

    ll res = 0;
    rep(i, n){
        ll time = max(0ll, t-dist[i]-distr[i]);
        ll reward = time*a[i];

        res = max(res, reward);
    }

    cout << res << endl;

    return 0;
}