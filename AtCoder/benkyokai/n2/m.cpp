#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int n;
vector<ll> x, y, z;
vector<vector<ll>> dp;

ll rec(ll s, int v){
    if(dp[s][v] != -1) return dp[s][v];
    if(s == (1<<n)-1) return 0;

    ll ret = 1ll << 60;
    rep(nv, n){
        if(!(s & (1<<nv))){
            ret = min(ret, rec(s | (1<<nv), nv) + abs(x[v]-x[nv]) + abs(y[v]-y[nv]) + max(0ll, z[nv] - z[v]));
        }
    }

    return dp[s][v] = ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    x.resize(n);
    y.resize(n);
    z.resize(n);
    rep(i, n) cin >> x[i] >> y[i] >> z[i];

    dp.resize(1<<n, vector<ll>(n, -1));

    ll res = rec(0, 0);
    
    cout << res << endl;

    return 0;
}