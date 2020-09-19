#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

const int mod = 998244353;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;

    unordered_set<ll> st;
    vector<ll> m;
    rep(i, k){
        ll l, r;
        cin >> l >> r;

        for(ll j = l; j <= r; ++j) m.push_back(j);
    }
    // vector<ll> m;
    // for(ll i = 1; i <= n; ++i){
    //     if(st.count(i)) m.push_back(i);
    // }

    // for(ll e: m) cout << e << endl;

    vector<ll> dp(n+1, 0);
    dp[0] = 1;
    rep1(i, n){
        for(auto step: m){
            if(i-step < 0) continue;
            dp[i] = (dp[i] + dp[i-step]) % mod;
        }
    }

    cout << dp[n-1] << endl;

    return 0;
}