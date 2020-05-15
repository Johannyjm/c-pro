#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    while(1){
        int n;
        cin >> n;

        if(n == 0) break;

        vector<int> w(n);
        rep(i, n) cin >> w[i];

        const int INF = 1001001001;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -INF));
        rep(i, n+1){
            dp[i][i] = 0;
            if(i < n) dp[i][i+1] = 0;
        }

        for(int r = 2; r < n+1; ++r) rep(i, n-r+1){
            int j = i + r;

            if(dp[i+1][j-1] == j-i-2){
                if(abs(w[i] - w[j-1]) <= 1) dp[i][j] = max(dp[i][j], j-i);
                else dp[i][j] = max(dp[i][j], j-i-2);
            }

            for(int k = i; k < j; ++k){
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }

        rep(i, n+1){
            rep(j, n+1) cout << dp[i][j] << " ";
            cout << endl;
        }

        cout << dp[0][n] << endl;
    }

    return 0;
}