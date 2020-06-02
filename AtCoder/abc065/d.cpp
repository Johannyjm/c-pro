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

    int n;
    cin >> n;

    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    vector<pair<int, int>> p_x(n), p_y(n);
    rep(i, n){
        p_x[i] = make_pair(x[i], i);
        p_y[i] = make_pair(y[i], i);
    }

    sort(p_x.begin(), p_x.end());
    sort(p_y.begin(), p_y.end());

    vector<pair<int, pair<int, int>>> dist;
    rep(i, n-1){
        dist.push_back(make_pair(abs(p_x[i].first - p_x[i+1].first), make_pair(p_x[i].second, p_x[i+1].second)));
        dist.push_back(make_pair(abs(p_y[i].first - p_y[i+1].first), make_pair(p_y[i].second, p_y[i+1].second)));
    }

    sort(dist.begin(), dist.end());

    // rep(i, dist.size()) cout << dist[i].first << " ";
    // cout << endl;

    UnionFind uf(n);
    int res = 0;
    rep(i, dist.size()){
        int cost = dist[i].first;
        int from = dist[i].second.first;
        int to = dist[i].second.second;

        if(uf.find(from) != uf.find(to)){
            res += cost;
            uf.unite(from, to);
        }
    }

    cout << res << endl;

    return 0;
}