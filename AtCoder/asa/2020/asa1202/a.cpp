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

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll s, p;
    cin >> s >> p;

    set<ll> st = divisor(p);
    for(auto n: st){
        ll m = p/n;
        if(n+m == s){
            puts("Yes");
            return 0;
        }
    }

    puts("No");

    return 0;
}