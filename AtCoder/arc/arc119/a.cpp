#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

ll calc(ll a, ll b){
    return a * pow(2, b);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    ll b = 0;

    while(calc(1, b) <= n) ++b;
    --b;

    ll res = 1ll << 60;

    rep(i, b+1){
        ll a = n / pow(2, i);

        res = min(res, a+i+n-calc(a, i));
    }

    cout << res << endl;

    return 0;
}