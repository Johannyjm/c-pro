#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

struct UnionFind {
    vector<int> p;
    vector<int> r;

    UnionFind(int n){
        p.resize(n, -1);
        r.resize(n, 1);
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
    }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    vector<int> p(n);
    rep(i, n){
        cin >> p[i];
        if(p[i] != -1) --p[i];
    }

    UnionFind uf(n);
    ll cnt = 0;
    rep(i, n){
        if(p[i] == -1) continue;
        if(uf.find(i) != uf.find(p[i])){
            uf.unite(i, p[i]);
            ++cnt;
        }
    }


    ll res = 1;
    const ll MOD = 1e9+7;
    vector<vector<int>> seen(n, vector<int>(n, 0));
    rep(i, n){
        if(p[i] != -1) continue;
        ll sm = 0;
        rep(j, n){
            if(i == j) continue;
            if(seen[i][j] == 1) continue;

            if(uf.find(i) == uf.find(j)) sm += cnt;
            else sm += cnt+1;

            seen[i][j] = 1;
            seen[j][i] = 1;
        }
        cout << i << " " << sm << endl;
        sm %= MOD;
        res = (res * sm) % MOD;
    }

    cout << res << endl;

    return 0;
}