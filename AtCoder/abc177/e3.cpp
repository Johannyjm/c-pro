#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

ll gcd(ll m, ll n){
    ll tmp;
    while(m%n){
        tmp = n;
        n = m % n;
        m = tmp;
    }
    return n;
}

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

    int n;
    cin >> n;

    vector<ll> a(n);
    ll g;
    bool ispair = true;
    map<ll, ll> primes;
    rep(i, n){
        cin >> a[i];
        if(i == 0){
            g = a[i];
        }
        else{
            g = gcd(g, a[i]);
        }
        if(a[i] == 1) continue;
        if(ispair){
            set<ll> pri = prime_factor(a[i]).second;
            for(ll elem: pri){
                if(primes[elem] > 0){
                    ispair = false;
                    break;
                }
                ++primes[elem];
            }
        }
    }

    if(ispair) puts("pairwise coprime");
    else if(g == 1) puts("setwise coprime");
    else puts("not coprime");

    return 0;
}