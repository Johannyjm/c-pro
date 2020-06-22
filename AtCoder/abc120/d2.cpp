#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

struct UnionFind{
    vector<int> p;
    vector<int> r;
    vector<int> s;

    UnionFind(int n){
        p.resize(n, -1);
        r.resize(n, 1);
        s.resize(n, 1);
    }

    int find(int x){
        if(p[x] == -1) return x;
        else return p[x] = find(p[x]);
    }

    void unite(int x, int y){
        x = find(x);
        y = find(y);

        if(x == y) return;
        if(r[x] > r[y]) swap(x, y);
        if(r[x] == r[y]) ++r[y];

        p[x] = y;
        s[y] += s[x];
    }

    bool same(int x, int y){
        return find(x) == find(y);
    }
};

ll calcsm(ll n){
    return n*(n-1)/2;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> a(m), b(m);
    rep(i, m){
        cin >> a[i] >> b[i];
        --a[i], --b[i];
    }

    vector<ll> res(m, 0);
    res[m-1] = calcsm(n);

    UnionFind uf(n);
    for(int i = m-1; i>0; --i){

        if(uf.same(a[i], b[i])) res[i-1] = res[i];
        else{
            ll n1 = uf.s[a[i]];
            ll n2 = uf.s[b[i]];
            res[i-1] = res[i] - n1*n2;
            
            uf.unite(a[i], b[i]);

        }
    }

    rep(i, m) cout << res[i] << endl;

    return 0;
}