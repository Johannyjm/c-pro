#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;

    vector<ll> a(k), b(k);
    map<ll, ll> mp;
    rep(i, k) {
        cin >> a[i] >> b[i];
        --a[i];
        mp[a[i]] = b[i];
    }

    ll dp[n][3][3] = {0};
    const ll mod = 10000;

    dp[1][0][0] = 1;
    dp[1][1][0] = 1;
    dp[1][2][0] = 1;

    dp[1][0][1] = 1;
    dp[1][1][1] = 1;
    dp[1][2][1] = 1;

    dp[1][0][2] = 1;
    dp[1][1][2] = 1;
    dp[1][2][2] = 1;

    if(mp[0] == 1) rep(i, 3) {
        dp[1][1][i] = 0;
        dp[1][2][i] = 0;
    }
    if(mp[0] == 2) rep(i, 3) {
        dp[1][0][i] = 0;
        dp[1][2][i] = 0;
    }
    if(mp[0] == 3) rep(i, 3) {
        dp[1][0][i] = 0;
        dp[1][1][i] = 0;
    }

    if(mp[1] == 1) rep(i, 3) {
        dp[1][i][1] = 0;
        dp[1][i][2] = 0;
    }
    if(mp[1] == 2) rep(i, 3) {
        dp[1][i][0] = 0;
        dp[1][i][2] = 0;
    }
    if(mp[1] == 3) rep(i, 3) {
        dp[1][i][0] = 0;
        dp[1][i][1] = 0;
    }

    for(ll d = 2; d < n; ++d){
        dp[d][0][0] = (dp[d-1][1][0] + dp[d-1][2][0]) % mod;
        dp[d][1][0] = (dp[d-1][0][1] + dp[d-1][1][1] + dp[d-1][2][1]) % mod;
        dp[d][2][0] = (dp[d-1][0][2] + dp[d-1][1][2] + dp[d-1][2][2]) % mod;

        dp[d][0][1] = (dp[d-1][0][0] + dp[d-1][1][0] + dp[d-1][2][0]) % mod;
        dp[d][1][1] = (dp[d-1][0][1] + dp[d-1][2][1]) % mod;
        dp[d][2][1] = (dp[d-1][0][2] + dp[d-1][1][2] + dp[d-1][2][2]) % mod;

        dp[d][0][2] = (dp[d-1][0][0] + dp[d-1][1][0] + dp[d-1][2][0]) % mod;
        dp[d][1][2] = (dp[d-1][0][1] + dp[d-1][1][1] + dp[d-1][2][1]) % mod;
        dp[d][2][2] = (dp[d-1][0][2] + dp[d-1][1][2]) % mod;

        if(mp[d] == 1) rep(i, 3){
            dp[d][i][1] = 0;
            dp[d][i][2] = 0;
        }
        if(mp[d] == 2) rep(i, 3){
            dp[d][i][0] = 0;
            dp[d][i][2] = 0;
        }
        if(mp[d] == 3) rep(i, 3){
            dp[d][i][0] = 0;
            dp[d][i][1] = 0;
        }
    }

    ll res = 0;
    rep(i, 3) rep(j, 3){
        res = (res + dp[n-1][i][j]) % mod;
    }

    cout << res << endl;

    return 0;
}