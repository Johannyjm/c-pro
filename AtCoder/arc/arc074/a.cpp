#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll h, w;
    cin >> h >> w;

    if(h%3==0 || w%3==0){
        cout << 0 << endl;
        return 0;
    }

    ll res = 1ll<<60;
    
    ll a = h/2;
    ll b = h - a;
    for(ll c = 1; c < w; ++c){
        ll sa = a*(w-c);
        ll sb = b*(w-c);
        ll sc = c*h;

        res = min(res, max({sa, sb, sc}) - min({sa, sb, sc}));
    }
    a = w/2;
    b = w - a;
    for(ll c = 1; c < h; ++c){
        ll sa = a*(h-c);
        ll sb = b*(h-c);
        ll sc = c*w;

        res = min(res, max({sa, sb, sc}) - min({sa, sb, sc}));
    }

    a = w/3;
    b = (w-a)/2;
    ll c = w - a - b;
    res = min(res, max({a*h, b*h, c*h}) - min({a*h, b*h, c*h}));

    a = h/3;
    b = (h-a)/2;
    c = h - a - b;
    res = min(res, max({a*w, b*w, c*w}) - min({a*w, b*w, c*w}));


    cout << res << endl;    

    return 0;
}