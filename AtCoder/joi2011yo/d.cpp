#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    --n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    int ans;
    cin >> ans;

    vector<vector<ll>> dp(n, vector<ll>(21, 0));
    dp[0][a[0]] = 1;

    rep1(i, n){
        rep(j, 21){
            if(dp[i-1][j]){
                if(j-a[i] >= 0) dp[i][j-a[i]] += dp[i-1][j];
                if(j+a[i] <= 20) dp[i][j+a[i]] += dp[i-1][j];
            }
        }
    }

    cout << dp[n-1][ans] << endl;

    return 0;
}