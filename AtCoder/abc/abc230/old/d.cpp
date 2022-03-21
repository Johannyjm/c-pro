#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, d;
    cin >> n >> d;
    vector<ll> l(n), r(n);
    rep(i, n) cin >> l[i] >> r[i];

    map<ll, ll> mp;
    rep(i, n){
        ++mp[l[i]];
        --mp[r[i]+1];
    }

    for(auto k: mp){
        
    }

    return 0;
}