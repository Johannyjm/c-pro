#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

ll n, m;
ll x[5500], c[5500], y[5500];
unordered_map<ll, ll> cy;
// vector<vector<vector<ll>>> dp;//[5500][5500][2];
vector<vector<ll>> dp;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    
    rep(i, n) cin >> x[i+1];
    rep(i, m) cin >> c[i] >> y[i];
    rep(i, m) cy[c[i]] = y[i];

    // rep(i, 5500) rep(j, 5500) rep(k, 2) dp[i][j][k] = -1;
    // dp.resize(5500, vector<vector<ll>>(5500, vector<ll>(2, -1)));
    dp.resize(5500, vector<ll>(2, -1));

    // dp[1][1][1] = x[1] + cy[1];
    // dp[1][0][0] = 0;
    dp[1][1] = x[1] + cy[1];
    dp[0][0] = 0;


    rep1(i, n){
        vector<vector<ll>> tmp(5500, vector<ll>(2, -1));
        rep(j, n){
            if(dp[j][0] != -1) tmp[j+1][1] = max(tmp[j+1][1], dp[j][0] + x[i+1] + cy[1]);
            if(dp[j][1] != -1) tmp[j+1][1] = max(tmp[j+1][1], dp[j][1] + x[i+1] + cy[j+1]);
            if(dp[j][0] != -1) tmp[0][0] = max(tmp[0][0], dp[j][0]);
            if(dp[j][1] != -1) tmp[0][0] = max(tmp[0][0], dp[j][1]);
        }
        // rep(j, 5500){
        //     dp[i+1][j+1][1] = tmp[j+1][1];
        // }
        dp = tmp;
        // dp[i+1][0][0] = tmp[0][0];
    }

    ll res = 0;
    rep(j, 5500){
        res = max(res, dp[j][1]);
    }

    // rep(i, 10){
    //     cout << i << endl;
    //     rep(j, 10) cout << dp[i][j][0] << " ";
    //     cout << endl;
    //     rep(j, 10) cout << dp[i][j][1] << " ";
    //     cout << endl;

    //     cout << endl;
    // }

    cout << res << endl;

    return 0;
}