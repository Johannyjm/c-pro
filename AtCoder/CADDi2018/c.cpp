#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, p;
    cin >> n >> p;
    
    if(n==1) {
        cout << p << endl;
        return 0;
    }

    pair<map<ll, ll>, set<ll>> primes = prime_factor(p);
    map<ll, ll> mp = primes.first;
    set<ll> st = primes.second;

    ll res = 1;
    for(ll i: st){
        if(mp[i] >= n) res *= pow(i, mp[i]/n);
    }
    
    cout << res << endl;

    return 0;
}