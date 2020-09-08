#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

const ll mod = 1000000007;
ll mod_fac(ll n){
    ll ret = 1;
    for(ll i = 1; i <= n; ++i){
        ret = (ret*i) % mod;
    }
    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    
    vector<ll> t(n);
    rep(i, n) cin >> t[i];

    sort(t.begin(), t.end());

    ll res1 = 0;
    ll now = 0;
    map<ll, ll> mp;
    rep(i, n){
        now += t[i];
        res1 += now;
        ++mp[t[i]];
    }

    ll res2 = 1;
    for(auto itr = mp.begin(); itr != mp.end(); ++itr){
        ll m = itr->second;
        res2 = (res2 * mod_fac(m)) % mod;
    }

    cout << res1 << endl;
    cout << res2 << endl;

    return 0;
}