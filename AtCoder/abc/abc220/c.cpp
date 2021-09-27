#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll x;
    cin >> x;

    ll sm = 0;
    rep(i, n){
        sm += a[i];
        if(sm > x){
            cout << i+1 << endl;
            return 0;
        }
    }

    ll res = x / sm * n;
    x %= sm;
    ll now = 0;
    rep(i, n){
        now += a[i];
        if(now > x){
            cout << res + i+1 << endl;
            return 0;
        }
    }



    return 0;
}