#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;

    if(n%2){
        cout << 0 << endl;
        return 0;
    }

    ll res = 0;
    ll N = n/2;

    for (ll i = 1; i < 28; ++i){
        ll bottom = pow(5, i);
        res += N / bottom;
    }
    cout << res << endl;
}