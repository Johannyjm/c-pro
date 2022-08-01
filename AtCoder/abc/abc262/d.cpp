#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;

mint dp[110][110][110];

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    mint res = 0;
    for(ll d = 1; d <= n; ++d){
        vector<int> am(n);
        rep(i, n) am[i] = a[i] % d;

        rep(i, n) rep(j, n) rep(k, d) dp[i][j][k] = 0;
        // dp[0][1][am[0]] = 1;
        // rep(i, n){
        //     dp[i][1][am[i]] = 1;
        // }
        dp[0][0][0] = 1;
        rep(i, n) rep(j, d+1) rep(k, d){
            // if(dp[i][j][k].val() == 0) continue;
            // not choose
            dp[i+1][j][k] += dp[i][j][k];
            // cout << dp[i+1][j][k].val() << " " << i+1 << " " << j << " " << k << endl;

            // choose
            if(j != d) dp[i+1][j+1][(k+am[i])%d] += dp[i][j][k];
            // cout << dp[i+1][j+1][(k+am[i])%d].val() << " " << i+1 << " " << j+1 << " " << (k+am[i])%d << endl;
            // cout << endl;
        }

        // mint sm = 0;
        // rep(k, d) sm += dp[n][d][0];

        // res += sm;

        // cout << d << " " << sm.val() << endl;

        res += dp[n][d][0];
    }

    cout << res.val() << endl;

    return 0;
}