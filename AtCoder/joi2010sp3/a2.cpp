#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    vector<tuple<int, int, int>> d;
    rep(_, m){
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;

        d.push_back(make_tuple(c, a, b));        
    }

    sort(d.begin(), d.end());

    UnionFind uf(n);
    vector<int> costs;
    for(auto edge: d){
        int cost = get<0>(edge);
        int from = get<1>(edge);
        int to = get<2>(edge);

        if(uf.find(from) != uf.find(to)){
            costs.push_back(cost);
            uf.unite(from, to);
        }
    }

    int res = 0;
    rep(i, costs.size() - k + 1) res += costs[i];

    cout << res << endl;

    return 0;
}