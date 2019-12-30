#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll l, r;
    cin >> l >> r;

    if(r-l>2019){
        cout << 0 << endl;
        return 0;
    }

    ll res = 2019;
    ll MOD = 2019;
    for (ll i = l; i <= r-1; ++i){
        for(ll j = i+1; j <= r; ++j){
            res = min(res, (i*j)%MOD);
        }
    }
    cout << res << endl;
}