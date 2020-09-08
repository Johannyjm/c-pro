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

    vector<vector<int>> dp(n, vector<int>(510000, 0));
    rep(j, 510000) dp[0][j] = a[0] * (j/b[0]);
    rep1(i, n) rep(j, 510000){
        if(j < b[i]) dp[i][j] = dp[i-1][j];
        else dp[i][j] = max(dp[i-1][j], dp[i][j-b[i]] + a[i]);
    }

    rep(j, 510000){
        if(dp[n-1][j] >= h){
            cout << j << endl;
            return 0;
        }
    }

    return 0;
}