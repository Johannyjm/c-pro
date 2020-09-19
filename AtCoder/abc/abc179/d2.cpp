#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

const int mod = 998244353;
vector<ll> m;

ll dp[220000];
ll rec(ll n){
    if(dp[n] > 0) return dp[n];
    if(n == 0) return 1;

    ll ret = 0;
    for(auto step: m){
        if(n - step < 0) continue;
        
        ret = (ret + rec(n-step)) % mod;
    }

    return dp[n] = ret;
}


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;

    rep(i, k){
        ll l, r;
        cin >> l >> r;

        for(ll j = l; j <= r; ++j) m.push_back(j);
    }

    cout << rec(n-1) << endl;

    return 0;
}