#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;


class UnionFind {
public:
    vector <ll> par; // 各元の親を表す配列
    vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)

    // Constructor
    UnionFind(ll sz_): par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
        for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }

    // Member Function
    // Find
    ll root(ll x) { // 根の検索
        while (par[x] != x) {
            x = par[x] = par[par[x]]; // x の親の親を x の親とする
        }
        return x;
    }

    // Union(Unite, Merge)
    bool merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける）
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool issame(ll x, ll y) { // 連結判定
        return root(x) == root(y);
    }

    ll size(ll x) { // 素集合のサイズ
        return siz[root(x)];
    }
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    
    vector<ll> a(m), b(m), y(m);
    vector<pair<ll, pair<int, int>>> edges(m);
    for(int i = 0; i < m; ++i){
        cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
        --edges[i].second.first;
        --edges[i].second.second;
    }

    sort(edges.begin(), edges.end(), greater<pair<ll, pair<int, int>>>());

    int q;
    cin >> q;
    vector<pair<pair<ll, int>, int>> queries(q);
    for(int i = 0; i < q; ++i){
        cin >> queries[i].first.second >> queries[i].first.first;
        --queries[i].first.second;
        queries[i].second = i;
    }

    sort(queries.begin(), queries.end(), greater<pair<pair<ll, int>, int>>());
    
    UnionFind uf(n);
    ll newest = edges.front().first;
    int ptr = 0;
    vector<ll> res(q);
    for(int i = 0; i < q; ++i){
        int v = queries[i].first.second;
        ll w = queries[i].first.first;

        if(w >= newest){
             res[queries[i].second] = uf.size(v);
        }

        else{
            while(edges[ptr].first > w){
                int from = edges[ptr].second.first;
                int to = edges[ptr].second.second;
                uf.merge(from, to);
                newest = edges[ptr].first;
                ++ptr;
            }
            res[queries[i].second] = uf.size(v);
        }
    }

    for(int i = 0; i < q; ++i) cout << res[i] << "\n";
    

    return 0;
}
