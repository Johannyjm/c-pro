#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll mod_add(ll a, ll b){
    return ((a % MOD) + (b % MOD)) % MOD;
}

ll mod_sub(ll a, ll b){
    return ((a + MOD) - b) % MOD;
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

ll mod_fac(ll n){
    ll ret = 1;
    for(ll i = 1; i <= n; ++i){
        ret = (ret*i) % MOD;
    }
    return ret;
}

ll mod_comb(ll n, ll k){
    ll numerator = 1;
    for(ll i = 0; i < k; ++i){
        numerator = numerator*(n-i) % MOD;
    }
    ll denominator = mod_fac(k);
    return mod_div(numerator, denominator);
}


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int s;
    cin >> s;
    int n = s/3;

    int res = 0;
    rep1(i, n+1){
        int m = s-3*i;
        if(m<0) break;

        // cout << mod_comb(m+i-1, i-1) << endl;
        res = (res + mod_comb(m+i-1, i-1)) % MOD;
    }

    cout << res << endl;

    return 0;
}