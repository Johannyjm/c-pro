#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

pair<map<ll, ll>, set<ll>> prime_factor(ll n){
    map<ll, ll> res;
    set<ll> primes;
    for(ll i = 2; i*i <= n; ++i) {
        if(n%i==0) primes.insert(i);

        while(n%i == 0){
            ++res[i];
            n /= i;
        }
    }
    if(n != 1) {
        res[n] = 1;
        primes.insert(n);
    }
    return make_pair(res, primes);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll l, r;
    cin >> l >> r;

    ll res = 0;
    for(ll x = 1; x <= r; ++x){
        map<ll, ll> factor = prime_factor(x).first;
        set<ll> seen;

        vector<ll> f;
        for(auto key: factor){
            rep(i, key.second) f.push_back(key.first);
        }
        cout << x << endl;
        for(auto e: f) cout << e << " ";
        cout << endl;
        ll sm = 0;
        int m = f.size();
        rep1(i, (1<<m)-1){
            ll base = 1;
            rep(j, m){
                if(i & (1<<j)){
                    base *= f[j];
                }
            }
            if(seen.count(base)) continue;
            // cout << 
            sm += (r / base) - (l / base);// - ((r / x) - (x / x));
            seen.insert(base);
        }

        cout << sm << endl;
        cout << endl;
        res += sm;
    }

    cout << res << endl;

    return 0;
}