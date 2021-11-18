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
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    vector<vector<mint>> dp(n, vector<mint>(3300, 0));
    for(int i = a[0]; i <= b[0]; ++i){
        dp[0][i] = 1;
    }

    rep(i, n-1){
        for(int j = a[i]; j <= b[i]; ++j){
            int from = max(j, a[i+1]);
            int to = b[i+1];

            dp[i+1][from] += dp[i][j];
            dp[i+1][to+1] -= dp[i][j];
        }

        for(int j = 0; j < 3200; ++j){
            dp[i+1][j+1] += dp[i+1][j];
        }
    }

    mint res = 0;
    for(int i = a.back(); i <= b.back(); ++i){
        res += dp[n-1][i];
    }

    cout << res.val() << endl;
    
    return 0;
}