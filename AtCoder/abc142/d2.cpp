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

    ll a, b;
    cin >> a >> b;
    
    pair<map<ll, ll>, set<ll>> pfpair_a = prime_factor(a);
    pair<map<ll, ll>, set<ll>> pfpair_b = prime_factor(b);

    map<ll, ll> pf_a = pfpair_a.first;
    map<ll, ll> pf_b = pfpair_b.first;

    int res = 1; // 1: not prime number but common divisor
    for(auto prime: pfpair_a.second){
        if(pf_a[prime]>0 && pf_b[prime]>0) ++res;
    }

    cout << res << endl;

    return 0;
}