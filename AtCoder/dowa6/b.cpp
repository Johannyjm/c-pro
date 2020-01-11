#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

ll fac(ll n){
    ll MOD = 1000000007;
    ll res = n;
    rep1(i, n) res = res*i%MOD;

    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    ll x[n];
    ll diff[n-1];
    rep(i, n) {
        cin >> x[i];
        if(i>0) diff[i-1] = x[i] - x[i-1];
    }

    ll res = 0;
    ll FAC = fac(n-1);
    ll MOD = 1000000007;
    rep(i, n-1){
        res += diff[i] * FAC % MOD;
    }

    cout << res << endl;
    
}