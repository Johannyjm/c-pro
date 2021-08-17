#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

ll r, b, x, y;
bool check(ll m){
    ll rrest = r - m;
    ll brest = b - m;
    if(rrest < 0 || brest < 0) return false;
    
    rrest /= x-1;
    brest /= y-1;

    return rrest + brest >= m;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> r >> b >> x >> y;

    ll ok = -1;
    ll ng = 1ll << 60;

    while(ng - ok > 1){
        ll mid = (ng + ok) / 2;

        if(check(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;

    return 0;
}