#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

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
        return (k % MOD) * (x % MOD);
    }
}

ll mod_div(ll a, ll b){
    return mod_mul(a, mod_pow(b, MOD - 2));
}

ll calc_subcomb(ll num, ll k){
    ll ret;
    ll over = 1;
    ll under = 1;
    for (ll i = num; i > num-k; --i){
        over = mod_mul(over, i);
    }
    for(ll i = 1; i <= k; ++i){
        under = mod_mul(under, i);
    }

    ret = mod_div(over, under);
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, a, b;
    cin >> n >> a >> b;

    ll all = mod_pow(2, n) - 1;

    ll sub_a = calc_subcomb(n, a);
    ll sub_b = calc_subcomb(n, b);

    cout << ((all + MOD - sub_a)%MOD + MOD - sub_b) % MOD << endl;



    return 0;
}