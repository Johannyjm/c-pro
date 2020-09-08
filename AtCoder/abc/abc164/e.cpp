#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

struct Edge{
    ll to;
    ll cost;
    ll weight;
    Edge(ll t, ll c, ll w): to(t), cost(c), weight(w) {}
};

using Graph = vector<vector<Edge>>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m, s;
    cin >> n >> m >> s;

    Graph g(n);
    rep(i, m){
        ll u, v, a, b;
        cin >> u >> v >> a >> b;

        --u;
        --v;
        g[u].push_back(Edge(v, a, b));
        g[v].push_back(Edge(u, a, b));
    }

    vector<ll> c(n), d(n);
    rep(i, n) cin >> c[i] >> d[i];

    const ll INF = 1001001001;
    vector<ll> costs(n, INF);
    costs[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(auto nv: g[v]){
            if(costs[nv.to] != INF) continue;
            costs[nv.to] = costs[v] + nv.cost;
            q.push(nv.to);
        }
    }

    rep(i, n) cout << costs[i] << " ";
    cout << endl;

    return 0;
}