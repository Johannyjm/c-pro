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

ll gcd(ll a, ll b){
    if(a == 0) return b;
    else return gcd(b%a, a);
}

bool is_prime(int n){
    if(n == 1) return false;
    
    for(int i = 2; i*i <= n; ++i){
        if(n%i == 0) return false;
    }

    return true;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll a, b;
    cin >> a >> b;

    ll res = 1;
    for(int i = a; i <= b; ++i){
        pair<map<ll, ll>, set<ll>> p = prime_factor(i);
        if(i!=2 && p.second.size() == 1) continue;
        for(auto k: p.first){
            ll now = i;
            while(now <= b){
                now += k.second;
                if(now > b) break;
                res = max(res, gcd(i, now));
            }
        }
    }

    cout << res << endl;

    return 0;
}