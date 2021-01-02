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

    ll n, m;
    cin >> n >> m;

    ll elem = m/n;
    ll mod = m%n;

    ll res = gcd(elem, elem+mod);
    ll a = elem;
    ll b = elem+mod;
    rep(_, min(5000000ll, elem)){
        --a;
        b += n-1;
        if(a == 0) break;
        // cout << a << " " << b << " " << gcd(a, b) << endl;

        res = max(res, gcd(a, b));
    }

    a = 1;
    b = elem+mod + (n-1)*(elem-1);
    res = max(res, gcd(a, b));
    rep(_, min(5000000ll, elem)){
        ++a;
        b -= n-1;
        if(b<=0) break;

        res = max(res, gcd(a, b));
    }

    cout << res << endl;

    return 0;
}