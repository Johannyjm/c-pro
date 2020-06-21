#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

struct UnionFind{
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

    int res = 0;
    rep(i, m){
        UnionFind uf(n);

        rep(j, m){
            if(j == i) continue;

            uf.unite(a[j], b[j]);
        }

        set<int> grs;
        rep(j, n){
            grs.insert(uf.find(j));
        }

        if(grs.size() > 1) ++res;
    }

    cout << res << endl;


    return 0;
}