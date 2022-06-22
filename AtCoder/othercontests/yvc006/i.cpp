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

    ll n, m, k;
    cin >> n >> m >> k;

    if(k == 0){
        cout << mint(m).pow(n).val() << endl;
        return 0;
    }

    vector<vector<mint>> dp(1100, vector<mint>(5500, 0));
    rep1(j, m+1) dp[0][j] = 1;

    rep(i, n-1){
        rep1(j, m+1){

            if(j > k){
                int l = 1;
                int r = j-k;

                dp[i+1][l] += dp[i][j];
                dp[i+1][r+1] -= dp[i][j];
            }

            if(j+k <= m){
                int l = j+k;
                int r = m;
                
                dp[i+1][l] += dp[i][j];
                dp[i+1][r+1] -= dp[i][j];
            }
        }

        rep(j, m+10){
            dp[i+1][j+1] += dp[i+1][j];
        }
    }

    mint res = 0;
    rep1(j, m+1) res += dp[n-1][j];

    cout << res.val() << endl;


    return 0;
}