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

    vector<int> c(m);
    rep(i, m) cin >> c[i];
    sort(c.begin(), c.end());

    const int INF = 1001001001;
    vector<vector<int>> dp(m, vector<int>(n+1, INF));
    rep(i, n+1) dp[0][i] = i;

    rep1(i, m) rep(j, n+1){
        if(j < c[i]) dp[i][j] = dp[i-1][j];
        else dp[i][j] = min(dp[i-1][j], dp[i][j-c[i]] + 1);
    }

    cout << dp[m-1][n] << endl;

    return 0;
}