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

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    set<ll> bases;
    for(ll num: a){
        set<ll> primes = prime_factor(num).second;

        for(auto p: primes){
            bases.insert(p);
        }
    }

    vector<int> res(m+1, 0);
    for(auto base: bases){
        for(int k = base; k <= m; k += base){
            res[k] = 1;
        }
    }

    int resn = 0;
    rep1(i, m+1){
        if(res[i] == 0) ++resn;
    }

    cout << resn << endl;
    rep1(i, m+1){
        if(res[i] == 0) cout << i << endl;
    }


    return 0;
}