
typedef long long ll;
#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep1(i, n) for (ll i = 1; i < (n); ++i)
using namespace std;


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    map<ll, ll> pri_fac;
    map<ll, ll> pri_facs[n];
    set<ll> primes;

    rep(i, n){
        ll a;
        cin >> a;

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
    const ll MOD = 1000000007;
    rep(i, n){
        ll sub = 1;
        for(ll prime: primes){
            ll p = pri_fac[prime] - pri_facs[i][prime];
            if(p) {
                rep(j, p) sub = (sub * prime) % MOD;
            }
        }
        res = (res + sub) % MOD;
    }

    cout << res << endl;

    return 0;
}