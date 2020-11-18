#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, c;
    cin >> n >> c;
    vector<ll> x(n), v(n);
    rep(i, n) cin >> x[i] >> v[i];

    vector<ll> sm1(n+1, 0), cmx1(n+1);
    sm1[1] = v[0] - x[0];
    cmx1[1] = max(0ll, sm1[1]);
    ll prevx = x[0];
    ll res = max(0ll, sm1[1]);
    rep1(i, n){
        sm1[i+1] = sm1[i] + v[i] - (x[i]-prevx);
        cmx1[i+1] = max(cmx1[i], sm1[i+1]);
        res = max(res, sm1[i+1]);
        prevx = x[i];
    }

    for(auto e: sm1) cout << e << " ";
    cout << endl;

    vector<ll> sm2(n+1, 0), cmx2(n+1);
    sm2[1] = v[n-1] - (c-x[n-1]);
    cmx2[1] = max(0ll, sm2[1]);
    res = max(res, sm2[1]);
    prevx = x[n-1];
    rep1(i, n){
        sm2[i+1] = v[n-i-1] - (prevx-x[n-i-1]);
        cmx2[i+1] = max(cmx2[i], sm2[i+1]);
        res = max(res, sm2[i+1]);
        prevx = x[n-i-1];
    }

    for(auto e: sm2) cout << e << " ";
    cout << endl;

    rep(i, n){
        ll cand = sm1[i+1] - x[i] + cmx2[n-i-1];
        res = max(res, cand);
    }

    for(int i = n-1; i >= 0; --i){
        ll cand = sm2[n-i] - (c-x[i]) + cmx1[i-1];
        res = max(res, cand);
    }

    cout << res << endl;

    return 0;
}