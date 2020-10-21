#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

ll n, k;
vector<ll> x, y;
int valcount(int xi, int xj, int yi, int yj){
    int ret = 0;
    ll a = min(x[xi], x[xj]);
    ll b = max(x[xi], x[xj]);
    ll c = min(y[yi], y[yj]);
    ll d = max(y[yi], y[yj]);

    rep(i, n){
        if(a<=x[i] && x[i]<=b && c<=y[i] && y[i]<=d) ++ret;
    }

    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    x.resize(n);
    y.resize(n);
    rep(i, n) cin >> x[i] >> y[i];

    ll res = 9223372036854775807;
    rep(xi, n) rep(xj, n) rep(yi, n) rep(yj, n){
        if(xi >= xj || yi >= yj) continue;

        if(valcount(xi, xj, yi, yj) >= k){
            res = min(res, abs(x[xi]-x[xj])*abs(y[yi]-y[yj]));
        }
    }

    cout << res << endl;


    return 0;
}