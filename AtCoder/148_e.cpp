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
    for(ll i = 1; i < 20; ++i){
        ll bottom10 = pow(10, i);
        if(bottom10>n)continue;

        res += n / bottom10;
    }
    for(ll i = 1; i < 13; ++i){
        ll bottom50 = pow(50, i);
        if(bottom50>n)continue;

        res += n / bottom50;
    }
    cout << res << endl;

}