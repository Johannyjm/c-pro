#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

ll fac(ll n){
    ll MOD = 1000000007;
    ll res = n;
    rep1(i, n) res = res%MOD*i%MOD;

    return res%MOD;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    ll x[n];
    ll diff[n-1];
    rep(i, n) {
        cin >> x[i];
        if(i>0) diff[i-1] = x[i] - x[i-1];
    }

    ll res = 0;
    ll MOD = 1000000007;
    ll FAC = fac(n-1);
    ll FACT = 0;

    rep(i, n-1){
        FACT = (FACT + FAC / (i+1)) % MOD;
        res += (diff[i]%MOD  * FACT % MOD)%MOD;
        res %= MOD;
    }

    cout << res << endl;
}