#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

struct Edge{
    ll to;
    ll weight;
    Edge(ll t, ll w): to(t), weight(w) {}
};
using Graph = vector<vector<Edge>>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    Graph g(n);
    rep(i, n-1){
        ll a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        g[a].push_back(Edge(b, c));
        g[b].push_back(Edge(a, c));
    }

    ll q, k;
    cin >> q >> k;
    --k;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push(make_pair(0, k));
    const ll INF = 1LL << 60;
    vector<ll> dist(n, INF);
    dist[k] = 0;
    while(!pq.empty()){
        pair<ll, ll> p = pq.top();
        pq.pop();
        int v = p.second;

        for(auto ne: g[v]){
            if(dist[v] + ne.weight < dist[ne.to]){
                dist[ne.to] = dist[v] + ne.weight;
                pq.push(make_pair(dist[ne.to], ne.to));
            }
        }
    }

    // rep(i, n) cout << dist[i] << " ";
    // cout << endl;

    rep(i, q){
        ll x, y;
        cin >> x >> y;
        --x;
        --y;

        cout << dist[x] + dist[y] << "\n";
    }

    return 0;
}