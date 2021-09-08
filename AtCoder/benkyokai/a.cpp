#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

ll digit(ll num){
    ll ret = 0;
    while(num){
        ++ret;
        num /= 10;
    }
    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    ll mod = 10000000;
    ll now = 1;
    ll res = 0;
    for(ll i = 1; i <= n; ++i){
        now *= i;
        ll dbefore = digit(now);
        now %= mod;
        ll dafter = digit(now);

        res += dbefore - dafter;
        // cout << res << " " << dbefore << " " << dafter << endl;
    }
    // cout << now << " " << digit(now) << endl;
    res += digit(now);

    cout << res << endl;

    return 0;
}