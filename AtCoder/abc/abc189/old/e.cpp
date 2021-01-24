#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

pair<ll, ll> one(ll x, ll y){
    return {y, -x};
}

pair<ll, ll> two(ll x, ll y){
    return {-y, x};
}

pair<ll, ll> three(ll x, ll y, ll ax){
    return {ax + (ax - x), y};
}

pair<ll, ll> four(ll x, ll y, ll ax){
    return {x, ax + (ax - y)};
}


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    ll m;
    cin >> m;
    vector<pair<int, int>> op(m);
    rep(i, m){
        int cmd;
        cin >> cmd;
        if(cmd == 3 || cmd == 4){
            ll p;
            cin >> p;
            op[i] = {cmd, p};
        }
        else{
            op[i] = {cmd, -1};
        }
    }
    ll q;
    cin >> q;
    vector<ll> a(q), b(q);
    rep(i, q) cin >> a[i] >> b[i];

    vector<ll> xs(m+10), ys(m+10);
    xs[0] = 0;
    ys[0] = 0;
    rep(i, m){
        if(cmd)
    }

    return 0;
}