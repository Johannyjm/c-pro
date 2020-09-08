#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll mod_add(ll a, ll b){
    return ((a % MOD) + (b % MOD)) % MOD;
}
 
ll mod_mul(ll a, ll b){
    return ((a % MOD) * (b % MOD)) % MOD;
}

ll mod_pow(ll x, ll r){
    if (r == 0) return 1;

    else if (r == 1) return x % MOD;

    else if (r % 2 == 0){
        ll t = mod_pow(x, r/2) % MOD;
        return mod_mul(t, t);
    }

    else{
        ll t = mod_pow(x, r/2) % MOD;
        ll k = mod_mul(t, t);
        return ((k % MOD) * (x % MOD)) % MOD;
    }
}

ll mod_div(ll a, ll b){
    return mod_mul(a, mod_pow(b, MOD - 2));
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll x, y;
    cin >> x >> y;

    if((x+y)%3 != 0 || min(x, y)*2 < max(x, y)){
        cout << 0 << endl;
        return 0;
    }

    // coordinate transformation
    ll n = (x+y) / 3;
    x %= n;
    y %= n;

    // calc nCx
    ll numerator = 1;
    rep(i, x){
        numerator = mod_mul(numerator, (n-i));
    }

    ll denominator = 1;
    rep1(i, x+1){
        denominator = mod_mul(denominator, i);
    }
    
    ll res = mod_div(numerator, denominator);

    cout << res << endl;

    return 0;
}