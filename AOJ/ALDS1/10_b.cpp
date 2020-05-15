#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> r(n), c(n);
    rep(i, n) cin >> r[i] >> c[i];

    const int INF = 1001001001;
    vector<vector<int>> dp(n, vector<int>(n, INF));
    rep(i, n) dp[i][i] = 0;
    for(int w = 1; w < n; ++w) for(int i = 0; i < n-w; ++i){
        int j = i + w;
        cout << endl;
        cout << "w: " << w << ", i: "  << i << ", j: " << j << endl;
        for(int k = i; k < j; ++k){
            dp[i][i+w] = min(dp[i][i+w], dp[i][k] + dp[k+1][i+w] + r[i]*c[k]*c[j]);
        }

        rep(a, n) {
            rep(b, n) cout << dp[a][b] << " ";
            cout << endl;
        }
    }

    cout << endl;
    rep(i, n){
        rep(j, n) cout << dp[i][j] << " ";
        cout << endl;
    }

    cout << dp[0][n-1] << endl;

    return 0;
}