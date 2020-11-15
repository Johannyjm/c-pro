#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, w;
    cin >> n >> w;
    vector<ll> s(n), t(n), p(n);
    ll mxt = 0;
    rep(i, n){
        cin >> s[i] >> t[i] >> p[i];
        mxt = max(mxt, t[i]);
    }

    if(n == 1){
        if(p[0] <= w) puts("Yes");
        else puts("No");
        return 0;
    }

    vector<ll> dp(220000, 0);
    rep(i, n){
        dp[s[i]] += p[i];
        dp[t[i]] -= p[i];
    }

    rep1(i, mxt+10) dp[i] += dp[i-1];

    // rep(i, n) cout << dp[i] << " ";
    // cout << endl;

    rep(i, mxt+10){
        if(dp[i] > w){
            puts("No");
            return 0;
        }
    }

    puts("Yes");

    return 0;
}