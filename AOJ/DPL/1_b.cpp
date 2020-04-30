#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, wmax;
    cin >> n >> wmax;

    vector<int> v(n), w(n);
    rep(i, n) cin >> v[i] >> w[i];

    vector<vector<int>> dp(n, vector<int>(wmax+1, 0));
    rep(i, wmax+1) {
        if(i >= w[0]) dp[0][i] = v[0];
    }

    rep1(i, n) rep(j, wmax+1){
        if(j < w[i]) dp[i][j] = dp[i-1][j];
        else dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
    }

    cout << dp[n-1][wmax] << endl;


    return 0;
}