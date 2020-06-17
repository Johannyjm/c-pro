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

    vector<vector<int>> direct(n, vector<int>(n, 0));
    UnionFind uf(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        --a;
        --b;

        direct[a][b] = 1;
        direct[b][a] = 1;

        uf.unite(a, b);
    }

    int res = 0;
    rep(i, n) {
        int res = 0;
        rep(j, n){
        if(i==j) continue;
        if(uf.find(i) == uf.find(j) && direct[i][j] != 1) ++res;
        }
        cout << res << endl;
    }

    return 0;
}