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
    vector<int> w(n), v(n);
    rep(i, n) cin >> w[i] >> v[i];

    const int INF = 1001001001;
    vector<vector<int>> dp(n, vector<int>(110000, INF));
    dp[0][0] = 0;
    dp[0][v[0]] = w[0];
    rep1(i, n){
        rep(j, 110000){
            if(j < v[i]) dp[i][j] = dp[i-1][j];
            else{
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i]] + w[i]);
            }
        }
    }

    int res = 0;
    rep(j, 110000){
        if(dp[n-1][j] <= wmax){
            res = max(res, j);
        }
    }

    cout << res << endl;

    return 0;
}