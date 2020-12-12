#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

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

    ll n, x;
    cin >> n >> x;
    string s;
    cin >> s;

    const int mod = 1000000007;

    int cnt3 = 0;
    int cnt6 = 0;
    for(char c: s){
        if(c == 'S') ++cnt3;
        else ++cnt6;
    }

    if(cnt3*3 + cnt6*6 < abs(x)){
        cout << 0 << endl;
        return 0;
    }

    if(cnt3==0 && x%2==1){
        cout << 0 << endl;
        return 0;
    }

    cout << cnt3 << " " << cnt6 << endl;

    ll res = 0;
    for(ll i = 0; i <= cnt3; ++i){
        if(x%2!=i%2) continue;
        // if((abs(x) - i*3)%6 != 0) continue;
        
        int j = (abs(x) - i*3)/6;
        ll sm = mod_pow(2, cnt3-i)*mod_pow(3, cnt6-i) + mod_comb(cnt6, j)*mod_pow(3, cnt6-j);
        cout << i << " " << j << " " << sm << endl;
        res = (res+sm%mod)%mod;
    }

    cout << res << endl;

    return 0;
}