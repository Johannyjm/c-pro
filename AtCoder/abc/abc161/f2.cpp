#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

set<ll> divisor(ll n){
    set<ll> ret;
    for(ll i = 1; i*i <= n; ++i){
        if(n%i == 0){
            ret.insert(i);
            ret.insert(n/i);
        }
    }
    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    set<ll> res = divisor(n-1);
    res.erase(1);

    set<ll> div = divisor(n);
    div.erase(1);
    for(auto d: div){
        ll num = n;
        while(num%d == 0) num /= d;

        if(num%d == 1) res.insert(d);
    }

    cout << res.size() << endl;

    return 0;
}