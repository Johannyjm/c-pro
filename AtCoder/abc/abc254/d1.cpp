#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    ll res = 0;
    ll now = n;
    ll div = 2;
    ll sm = 1;
    for(ll now = n; now >= 1; --now){
        ll num = now*now;

        ++res;
        for(ll i = 2; i <= n; ++i){
            if(num % i == 0 && num / i <= n){
                res += 2;
            }
            if(num % i == 0 && num / i > n) break;
        }
    }

    cout << res << endl;

    return 0;
}