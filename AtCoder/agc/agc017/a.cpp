#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

ll comb(ll n, ll k){
    ll numerator = 1;
    k = min(k, n-k);
    for(ll i = n; i > n-k; --i) numerator *= i;

    ll denominator = 1;
    for(ll i = 1; i <= k; ++i) denominator *= i;

    ll ret = numerator / denominator;
    return ret;
}

int main(){

    ll n, p;
    cin >> n >> p;
    vector<ll> a(n);

    ll odd = 0;
    rep(i, n) {
        cin >> a[i];
        if(a[i]%2) ++odd;
    }

    ll even = n - odd;
    ll res = 0;
    if(p){
        ll max_odd = (odd+1)/2*2-1; // max odd number not greater than <odd>
        for(ll i = 1; i <= max_odd; i+=2){
            res += comb(odd, i);
        }
    }

    else{
        ll max_even = odd/2*2; // max even number not greater than <even>
        for(ll i = 0; i <= max_even; i+=2){
            res += comb(odd, i);
        }
    }

    cout << res * (1LL<<even) << endl;

    return 0;
}