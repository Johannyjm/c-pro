#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

ll a, b;
ll func(ll x){
    return a*x/b - a*(x/b);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> a >> b >> n;


    rep(i, 100){
        cout << func(i) << " ";
    }
    cout << endl;
    cout << func(b-1) << endl;

    ll res = 0;
    bool start = false;
    bool flg = false;
    for(ll i = 0; i < min(a*10, n+1); ++i){
        ll num = func(i);
        if(num) start = true;
        res = max(res, num);
        if(start && num==0){
            flg = true;
            break;
        }
    }

    if(!flg){
        flg = false;
        for(ll i = n; i > n - min(a*10, n+1); --i){
            ll num = func(i);
            res = max(res, num);
            if(num==0){
                flg = true;
                res = max(res, func(i-1));
                break;
            }
        }

        if(!flg){
            res = max(res, func(b-1));
        }

    }

    cout << res << endl;

    return 0;
}