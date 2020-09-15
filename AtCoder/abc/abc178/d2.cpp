#include <iostream>
#include <vector>
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

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio (false);

    ll s;
    cin >> s;
    
    vector<ll> dp(s+20, 0);
    dp[3] = dp[4] = dp[5] = 1;
    const int mod = 1000000007;
    for(ll i = 6; i < s+20; ++i){
        ll v = 0;
        for(ll j = i-3; j >= 6; --j){
            v = (v + mod_sub(dp[j], 1)) % mod;
        }
        dp[i] = (i-4 + v) % mod;
    }

    cout << dp[s] << endl;

    return 0;
}
