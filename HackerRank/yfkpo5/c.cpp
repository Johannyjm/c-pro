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

bool solve(ll n, ll k){
    
    auto [factors, primes] = prime_factor(k);

    for(ll p: primes){
        ll idx = factors[p];
        ll count = 0;
        ll base = p;
        
        while(base < n){
            count += n / base;
            base *= p;
        }

        if(idx > count){
            return true;
        }
    }

    return false;
    
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    for(ll i = 1; i <= 100; ++i){
        if(solve(n, n + i)){
            cout << n + i << endl;
            return 0;
        }
    }

    return 0;
}