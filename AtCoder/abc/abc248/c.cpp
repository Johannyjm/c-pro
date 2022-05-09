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

    vector<vector<mint>> dp(n, vector<mint>(k+1, 0));
    rep(i, m){
        dp[0][k-i-1] = 1;
    }
    rep1(i, n){
        rep(fr, k+1){
            rep1(j, m+1){
                int to = fr - j;
                if(to < 0) continue;

                dp[i][to] += dp[i-1][fr];
            }
        }
    }

    mint res = 0;
    rep(i, k+1){
        res += dp[n-1][i];
    }

    // rep(i, n){
    //     rep(j, k+1) cout << dp[i][j].val() << " ";
    //     cout << endl;
    // }

    cout << res.val() << endl;


    return 0;
}