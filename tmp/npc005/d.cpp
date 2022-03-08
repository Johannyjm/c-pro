#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<vector<mint>> dp(n+10, vector<mint>(9, 0));
    rep(i, 9) dp[1][i] = 1;

    rep1(i, n){
        rep(j, 9){
            if(j == 0) dp[i+1][j] += dp[i][j] + dp[i][j+1];
            else if(j == 8) dp[i+1][j] += dp[i][j] + dp[i][j-1];
            else dp[i+1][j] += dp[i][j] + dp[i][j-1] + dp[i][j+1];
        }
    }

    mint res = 0;
    rep(i, 10) res += dp[n][i];

    cout << res.val() << endl;

    return 0;
}