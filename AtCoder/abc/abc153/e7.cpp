#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, n;
    cin >> h >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    const int INF = 1001001001;
    vector<vector<int>> dp(n, vector<int>(22000, INF));
    dp[0][0] = 0;
    rep(j, 22000){
        if(j%a[0] == 0) dp[0][j] = b[0] * (j/a[0]);
    }

    rep1(i, n) rep(j, 22000){
        if(j < a[i]) dp[i][j] = dp[i-1][j];
        else dp[i][j] = min(dp[i-1][j], dp[i][j-a[i]] + b[i]);
    }

    int res = INF;
    for(int i = h; i < 22000; ++i){
        if(dp[n-1][i] != INF){
            res = min(res, dp[n-1][i]);
        }
    }

    cout << res << endl;

    return 0;
}