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
    for(int d = 1; d <= n; ++d){
        vector<int> am(n);
        rep(i, n) am[i] = a[i] % d;

        rep(i, 110) rep(j, 110) rep(k, 110) dp[i][j][k] = 0;
        dp[0][0][0] = 1;

        rep(i, n) rep(j, d+1) rep(k, d){

            dp[i+1][j][k] += dp[i][j][k];

            if(j != d) dp[i+1][j+1][(k+am[i])%d] += dp[i][j][k];
        }

        res += dp[n][d][0];

    }

    cout << res.val() << endl;

    return 0;
}