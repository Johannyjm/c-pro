#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

ll gcd(ll m, ll n){
    ll tmp;
    while(m%n){
        tmp = n;
        n = m % n;
        m = tmp;
    }
    return n;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<ll> l(n), r(n);
    ll g = 0;
    rep(i, n){
        g = gcd(g, a[i]);
        l[i] = g;
    }
    g = 0;
    rep(i, n){
        g = gcd(g, a[n-i-1]);
        r[n-i-1] = g;
    }

    // for(auto e: l) cout << e << " ";
    // cout << endl;
    // for(auto e: r) cout << e << " ";
    // cout << endl;

    ll res = max(r[1], l[n-2]);
    for(int i = 1; i < n-1; ++i){
        res = max(res, gcd(l[i-1], r[i+1]));
    }

    cout << res << endl;

    return 0;
}