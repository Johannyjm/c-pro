#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll a, b, x;

bool isPurchasable(ll ans){
    int d = to_string(ans).size();
    return a * ans + b * d <= x;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> a >> b >> x;

    if(a * 1 + b * 1 > x){
        cout << 0 << endl;
        return 0;
    }
    if(a * 1e9 + b * 10 <= x){
        cout << 1000000000 << endl;
        return 0;
    }

    /* Start of NIBUTAN!!!! */

    ll l = 1;
    ll r = 1e9;
    ll m = (l + r) / 2;

    while(abs(r - l) > 1){
        if(isPurchasable(m)){
            l = m;
        }
        else{
            r = m;
        }
        m = (l + r) / 2;
    }
    if(isPurchasable(r)) cout << r << endl;
    else cout << l << endl;




}