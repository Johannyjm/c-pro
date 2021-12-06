#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

ll floor_sm(ll n){
    ll ret = 0;
    for(ll i = 1; i*i <= n; ++i){
        ret += n / i;
    }

    return ret*2;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    ll res = 0;
    for(ll a = 1; a*a <= n; ++a){
        ll bc = n / a;
        res += floor_sm(bc);
    }

    cout << res*2 << endl;


    return 0;
}