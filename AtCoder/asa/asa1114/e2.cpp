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
    l[0] = a[0];
    rep1(i, n){
        l[i] = gcd(l[i-1], a[i]);
    }
    r[n-1] = a[n-1];
    rep1(i, n){
        r[n-i-1] = gcd(r[n-1], a[n-i-1]);
    }

    ll res = max(r[1], l[n-2]);
    for(int i = 1; i < n-1; ++i){
        res = max(res, gcd(l[i-1], r[i+1]));
    }

    cout << res << endl;

    return 0;
}