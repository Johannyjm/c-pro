#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

pair<map<ll, ll>, set<ll>> prime_factor(ll n){
    map<ll, ll> res;
    set<ll> primes;
    for(ll i = 2; i*i <= n; ++i) {
        if(n%i==0) primes.insert(i);

        while(n%i == 0){
            res[i]++;
            n /= i;
        }
    }
    if(n != 1) {
        res[n] = 1;
        primes.insert(n);
    }
    return make_pair(res, primes);
}

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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<ll> a(n);
    set<ll> primes;
    map<ll, ll> pf_lcm;

    rep(i, n){
        cin >> a[i];
        pair<map<ll, ll>, set<ll>> pf_pr = prime_factor(a[i]);
        map<ll, ll> pf = pf_pr.first;
        set<ll> pr = pf_pr.second;

        for(ll prime: pr){
            pf_lcm[prime] = max(pf_lcm[prime], pf[prime]);
            primes.insert(prime);
        }
    }

    ll LCM = 1;
    for(ll prime: primes){
        LCM = mod_mul(LCM, mod_pow(prime, pf_lcm[prime]));
    }
    ll res = 0;
    rep(i, n){
        res = mod_add(res, mod_div(LCM, a[i]));
    }

    cout << res << endl;
    
    return 0;
}