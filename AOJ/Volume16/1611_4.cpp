#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int n;
vector<ll> w;
vector<vector<ll>> dp;

ll rec(int l, int r){
    if(dp[l][r] != -1) return dp[l][r];
    if(r-l <= 1) return dp[l][r] = 0;
    if(r-l == 2){
        if(abs(w[l]-w[r-1]) <= 1) return dp[l][r] = 2;
        else return dp[l][r] = 0;
    }

    ll ret = 0;
    // ll cnt = 0;
    if(abs(w[l]-w[r-1]) <= 1){
        if(rec(l+1, r-1) == r-l-2) ret = r-l;
        // cout << l << " " << r << " " << cnt << endl;
    }

    for(int m = l+1; m < r; ++m){
        ret = max(ret, rec(l, m) + rec(m, r));
    }

    return dp[l][r] = ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<ll> res;
    while(1){
        cin >> n;
        if(n == 0) break;

        w.resize(n);
        rep(i, n) cin >> w[i];

        dp.assign(330, vector<ll>(330, -1));

        res.push_back(rec(0, n));

        // cout << endl;
        // rep(i, n+1){
        //     rep(j, n+1) cout << dp[i][j] << " ";
        //     cout << endl;
        // }
    }

    for(auto e: res) cout << e << endl;

    return 0;
}