#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

set<ll> divisor(ll n) {
    set<ll> ret;
    for(ll i = 1; i*i <= n; ++i) {
        if (n%i == 0) {
            ret.insert(i);
            if(i*i != n) ret.insert(n/i);
        }
    }
    return ret;
}

int f(ll a, ll b){
    int da = 0;
    while(a){
        a /= 10;
        ++da;
    }
    int db = 0;
    while(b){
        b /= 10;
        ++db;
    }
    return max(da, db);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    set<ll> d = divisor(n);
    int res = 100;
    for(auto e: d){
        ll a = e;
        ll b = n/a;

        res = min(res, f(a, b));   
    }

    cout << res << endl;

    return 0;
}