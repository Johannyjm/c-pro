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

    ll pt, pa;
    cin >> pt >> pa;
    rep(i, n-1){
        ll t, a;
        cin >> t >> a;
        
        ll t1 = t;
        ll a1 = a;
        if(pt > t1){
            ll m = (pt + t1 - 1) / t1;
            t1 *= m;
            a1 *= m;
        }
        if(pa > a1){
            ll m = (pa + a1 - 1) / a1;
            t1 *= m;
            a1 *= m;
        }

        ll t2 = t;
        ll a2 = a;
        if(pa > a2){
            ll m = (pa + a2 - 1) / a2;
            t2 *= m;
            a2 *= m;
        }
        if(pt > t2){
            ll m = (pt + t2 - 1) / t2;
            t2 *= m;
            a2 *= m;
        }

        pt = min(t1, t2);
        pa = min(a1, a2);
    }

    cout << pt + pa << endl;

    return 0;
}