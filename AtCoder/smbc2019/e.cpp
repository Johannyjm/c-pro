#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    if(a[0]){
        cout << 0 << endl;
        return 0;
    }

    vector<vector<ll>> dp(n, vector<ll>(3, 0));
    dp[0][0] = 1;
    rep1(i, n){
        int up_idx = -1;
        rep(j, 3){
            if(dp[i-1][j]==a[i]){
                up_idx = j;
                break;
            }
        }
        
        rep(j, 3){
            if(j==up_idx) dp[i][j] = dp[i-1][j] + 1;
            else dp[i][j] = dp[i-1][j];
        }

    }

    // rep(i, n){
    //     rep(j, 3) cout << dp[i][j] << " ";
    //     cout << endl;
    // }

    ll res = 3;
    ll const MOD = 1000000007;
    rep1(i, n){
        ll cand = 0;
        rep(j, 3){
            if(dp[i-1][j]+1 == dp[i][j]){
                rep(k, 3){
                    if(dp[i-1][k]+1 == dp[i][j]) ++cand;
                }
                break;
            }
        }
        res = res%MOD * cand%MOD;
        res %= MOD;
    }

    cout << res << endl;

    return 0;
}