#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    const int INF = 1001001001;
    vector<vector<int>> cost(n, vector<int>(n, INF));
    rep(i, n) cost[i][i] = 0;
    rep(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;

        cost[a][b] = c;
        cost[b][a] = c;
    }

    rep(k, n) rep(i, n) rep(j, n){
        cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
    }

    // rep(i, n){
    //     rep(j, n) cout << cost[i][j] << " ";
    //     cout << endl;
    // }

    int res = INF;
    rep(i, n){
        int mx = -1;
        rep(j, n){
            mx = max(mx, cost[i][j]);
        }
        res = min(res, mx);
    }

    cout << res << endl;

    return 0;
}