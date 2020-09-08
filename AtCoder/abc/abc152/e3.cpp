#include <bits/stdc++.h>
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

    vector<ll> A(n);
    map<ll, ll> pri_fac;
    map<ll, ll> pri_facs[n];
    set<ll> primes;

    rep(i, n){
        ll a;
        cin >> a;

        A[i] = a;
        ll tmp = a;
        ll cnt = 0;
        for(ll j = 2; j*j <= tmp; ++j) {
            if(n%j==0) primes.insert(j);

            while(tmp%j == 0){
                cnt++;
                tmp /= j;
            }

            if(pri_fac[j] < cnt) pri_fac[j] = cnt;
            pri_facs[i][j] = cnt;
        }
        if(tmp != 1) {
            pri_fac[tmp] = 1;
            pri_facs[i][tmp] = 1;
            primes.insert(tmp);
        }
    }

    ll res = 0;
    ll LCM = 1;
    for(ll prime: primes){
        LCM = mod_mul(LCM, mod_pow(prime, pri_fac[prime]));
        cout << prime << endl;
    }
    cout << LCM << endl;

    rep(i, n){
        res = mod_add(res, mod_div(LCM, A[i]));
    }

    cout << res << endl;

    return 0;
}