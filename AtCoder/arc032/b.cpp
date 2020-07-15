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
        r.resize(n, -1);
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

    UnionFind uf(n);
    rep(_, m){
        int a, b;
        cin >> a >> b;
        --a, --b;

        uf.unite(a, b);
    }

    set<int> st;
    rep(i, n) st.insert(uf.find(i));

    cout << st.size()-1 << endl;

    return 0;
}