#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

ll gcd(ll x, ll y){
    if(x == 0) return y;
    return gcd(y%x, x);
}

ll lcm(ll x, ll y){
    return x / gcd(x, y) * y; 
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    ll res = 1;
    rep(i, n){
        ll a;
        cin >> a;

        res = lcm(res, a);
    }

    cout << res << endl;

    return 0;
}