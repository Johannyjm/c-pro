#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

ll gcd(ll m, ll n){
    ll tmp;
    while(m%n){
        tmp = n;
        n = m % n;
        m = tmp;
    }
    return n;
}

ll lcm(ll m, ll n){
    return m / gcd(m, n) * n;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, W;
    cin >> n >> W;

    vector<ll> w(n), v(n);
    rep(i, n) cin >> w[i] >> v[i];

    vector<vector<ll>> dp(n, vector<ll>(W+1, 0));
    if(w[0] <= W) dp[0][w[0]] = v[0];
    rep1(i, n){
        rep(j, W+1){
            if(dp[i-1][j] == 0) continue;
            dp[i][j] = max(dp[i][j], dp[i-1][j]);

            ll idx = lcm((ll)j, w[i]);
            // cout << j << " " << w[i] << " " << idx << " " << dp[i-1][j] << " " << v[i] << endl;
            if(idx <= W) dp[i][idx] = max(dp[i][idx], dp[i-1][j] + v[i]);
        }

        if(w[i] <= W) dp[i][w[i]] = max({dp[i][w[i]], dp[i-1][w[i]], v[i]});
    }

    ll res = 0;
    rep(j, W+1) res = max(res, dp[n-1][j]);
    // rep(i, n){
    //     rep(j, W+1) cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    cout << res << endl;

    return 0;
}