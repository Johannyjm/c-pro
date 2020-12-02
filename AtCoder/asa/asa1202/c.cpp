#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;

    ll res = 0;
    for(ll x = 2; x <= 2*n; ++x){
        ll y = x - k;
        if(!(2<=y&&y<=2*n)) continue;

        ll cntx = x-1;
        ll cnty = y-1;
        if(x > n+1) cntx -= (x-n-1)*2;
        if(y > n+1) cnty -= (y-n-1)*2;
        res += cntx * cnty;
    }

    cout << res << endl;

    return 0;
}