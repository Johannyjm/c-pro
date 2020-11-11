#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<ll> sm;
    // int mxi = -1;
    // ll mx = -1001001001001;
    sm.push_back(0);
    rep(i, n){
        sm.push_back(sm[i] + a[i]);
        // if(sm[i]+a[i] >= mx){
        //     mxi = i;
        //     mx = sm[i] + a[i];
        // }
    }

    vector<ll> mxgain(n);
    ll mxg = -1001001001001;
    rep(i, n){
        mxg = max(mxg, sm[i+1]);
        mxgain[i] = mxg;
    }

    // for(auto e: mxgain) cout << e << " ";
    // cout << endl;

    ll now = a[0];
    ll res = max(0ll, now);
    rep1(i, n){
        res = max(res, now + mxgain[i]);
        now += sm[i+1];
    }

    cout << res << endl;



    return 0;
}