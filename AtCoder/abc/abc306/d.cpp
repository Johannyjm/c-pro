#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    const ll INF = 1ll << 60;
    vector<vector<ll>> dp(n, vector<ll>(2, -INF));

    if(x[0] == 0){
        dp[0][0] = y[0]; // ate to no problem
        dp[0][1] = 0; // broke
    }
    else{
        dp[0][0] = 0;
        dp[0][1] = y[0]; // broke
    }

    rep1(i, n){
        if(x[i] == 0){
            dp[i][0] = max({dp[i-1][1] + y[i], dp[i-1][0], dp[i-1][0] + y[i]});
            dp[i][1] = dp[i-1][1];
        }
        else{
            dp[i][0] = dp[i-1][0];
            dp[i][1] = max(dp[i-1][0] + y[i], dp[i-1][1]);
        }
    }

    // rep(i, n){
    //     if(dp[i][0] == -INF) cout << "-INF" << " ";
    //     else cout << dp[i][0] << " ";
    //     if(dp[i][1] == -INF) cout << "-INF" << " ";
    //     else cout << dp[i][1] << " ";
    //     cout << endl;
    //     cout << endl;
    // }

    cout << max(dp[n-1][0], dp[n-1][1]) << endl;

    return 0;
}