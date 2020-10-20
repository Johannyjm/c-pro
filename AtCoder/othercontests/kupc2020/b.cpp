#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n, vector<int>(k)), dp(n, vector<int>(k, 0));
    rep(i, n) rep(j, k) cin >> v[i][j];
    rep(j, k) dp[0][j] = 1;

    const int mod = 1000000007;
    vector<int> dps(k+1);
    rep1(i, n){
        dps.assign(k+1, 0);
        dps[1] = dp[i-1][0];
        rep1(j, k+1) dps[j] = (dps[j-1] + dp[i-1][k-1]) % mod;

        rep(j, k+1) cout << dps[j] << " ";
        cout << endl;

        rep(j, k){
            int idx = upper_bound(v[i-1].begin(), v[i-1].end(), v[i][j]) - v[i-1].begin();
            dp[i][j] = dps[idx] % mod;
        }
    }

    rep(i, n){
        rep(j, k) cout << dp[i][j] << " ";
        cout << endl;
    }

    int res = 0;
    rep(j, k) res = (res + dp[n-1][j]) % mod;
    cout << res << endl;

    return 0;
}