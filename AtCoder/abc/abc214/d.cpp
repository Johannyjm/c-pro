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
    Edge(int t, ll w): to(t), weight(w) {}
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<ll, pair<int, int>>> wuv(n-1);
    rep(i, n-1){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u;
        --v;

        wuv[i] = {w, {u, v}};
    }

    sort(wuv.begin(), wuv.end());
    dsu uf(n);

    ll res = 0;
    for(auto edge: wuv){
        // ll w = edge.first;
        // int u = edge.second.first;
        // int v = edge.second.second;

        auto [w, uv] = edge;
        auto [u, v] = uv;
        
        res += ll(uf.size(u)) * ll(uf.size(v)) * w;
        uf.merge(u, v);
    }

    cout << res << endl;


    return 0;
}