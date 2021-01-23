#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, d;
    cin >> n >> d;

    d *= d;

    int res = 0;
    rep(i, n){
        ll x, y;
        cin >> x >> y;
        ll d2 = x*x + y*y;

        if(d2 <= d) ++res;
    }

    cout << res << endl;

    return 0;
}