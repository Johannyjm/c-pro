#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

ll x, y, a, b;
bool check(ll lim){
    ll x_ = x;
    ll y_ = y;
    ll a_ = a;
    ll b_ = b;

    
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> x >> y >> a >> b;

    ll ok = 0;
    ll ng = y+10;

    while(abs(ng-ok) > 1){
        ll mid = (ok+ng) / 2;

        if(check(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;

    return 0;
}