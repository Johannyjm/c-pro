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

    vector<double> ans;
    while(1){
        int n;
        cin >> n;

        if(n == 0) break;

        vector<double> x(n), y(n), z(n), r(n);
        rep(i, n) cin >> x[i] >> y[i] >> z[i] >> r[i];

        vector<vector<double>> dist(n, vector<double>(n));
        vector<pair<double, pair<int, int>>> dp;
        rep(i, n) rep(j, n){
            if(i < j) continue;
            dist[i][j] = pow(pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2) + pow(z[i]-z[j], 2), 0.5);
            dist[i][j] = max(0.0, dist[i][j] - r[i] - r[j]);
            dist[j][i] = dist[i][j];

            dp.push_back(make_pair(dist[i][j], make_pair(i, j)));
        }

        sort(dp.begin(), dp.end());
        UnionFind uf(n);

        double res = 0;
        rep(i, dp.size()){
            double d = dp[i].first;
            int from = dp[i].second.first;
            int to = dp[i].second.second;

            if(uf.find(from) != uf.find(to)){
                res += d;
                uf.unite(from, to);
            }
        }



        // rep(i, n){
        //     rep(j, n) cout << dist[i][j] << " ";
        //     cout << endl;
        // }

        // cout << res << endl;
        ans.push_back(res);

    }

    rep(i, ans.size()) printf("%.3f\n", ans[i]);

    return 0;
}