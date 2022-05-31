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

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<mint>> dp(1100, vector<mint>(5500));
    rep(j, 5500) dp[1][j] = 1;
    for(int i = 2; i <= n; ++i){
        vector<mint> sm(5500, 0);
        sm[0] = dp[i-1][0];
        rep1(j, m+1) sm[j] = sm[j-1] + dp[i-1][j];

        rep(j, m+1){
            if(j-k >= 0) dp[i][j] += sm[j-k];
            if(j+k < m) dp[i][j] += sm[m] - sm[j+k];
        }

    }

    mint res = 0;
    rep(j, m+1) res += dp[n][j];

    cout << res.val() << endl;

    return 0;
}