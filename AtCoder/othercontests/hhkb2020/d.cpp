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
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        ll n, a, b;
        cin >> n >> a >> b;

        ll res = ((n-a+1)%MOD * (n-b+1)%MOD) %MOD;
        res = mod_sub(res, mod_sub((mod_pow(a, 2) + mod_pow(b, 2))%MOD, 1));
        cout << res << "\n";
    }

    return 0;
}