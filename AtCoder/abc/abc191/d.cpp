#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

ll x, y, r;

ll s2i(string s){
    ll ret = 0;
    int n = s.size();
    ll offset = 10000;
    rep(i, n){
        if(s[i] == '.'){
            offset = pow(10, 5-n+i);
            continue;
        }
        ret *= 10;
        ret += (s[i] - '0');
    }

    return ret * offset;
}

bool inside(ll a, ll b){
    a *= 10000;
    b *= 10000;
    return (x-a)*(x-a) + (y-b)*(y-b) <= r*r;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string X, Y, R;
    cin >> X >> Y >> R;

    x = s2i(X);
    y = s2i(Y);
    r = s2i(R);

    // cout << x << " " << y << " " << r << endl;
    // cout << x*x << " " << y*y << " " << r*r << endl;

    ll left = (x-r + 10000 - 1)/10000;
    ll right = (x+r)/10000;
    ll res = 0;
    for(int i = left-10; i <= right+10; ++i){
        // calc top
        ll ok = y/10000 - 10;
        bool nothing = false;
        while(!inside(i, ok)){
            ++ok;
            if(ok == y/10000 +10){
                nothing = true;
                break;
            }
        }
        if(nothing) continue;
        // if(inside(i, y/10000)) ok = y/10000;
        // else if(inside(i, (y+10000-1)/10000)) ok = (y+10000-1)/10000;
        // else continue;
        
        ll ok2 = ok;
        ll ng = (y+r)/10000 + 10;
        while(ng - ok > 1){
            ll mid = (ok + ng)/2;

            if(inside(i, mid)) ok = mid;
            else ng = mid;
        }
        ll top = ok;

        // calc bottom
        ll ng2 = (y-r)/10000 - 10;
        while(ok2 - ng2 > 1){
            ll mid = (ok2 + ng2)/2;

            if(inside(i, mid)) ok2 = mid;
            else ng2 = mid;
        }
        ll bottom = ok2;
        // cout << i << " " << top << " " << bottom << endl;
        res += top - bottom + 1;
    }

    cout << res << endl;

    return 0;
}