#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int n;
vector<ll> a;
vector<vector<ll>> sm;
ll const INF = 1ll<<60;
ll dp[440][440];

ll rec(int l, int r){
    if(dp[l][r] > 0) return dp[l][r];
    if(r-l == 1) return 0;//dp[l][r] = a[l];
    if(r-l == 2) return dp[l][r] = a[l]+a[r-1];

    ll ret = INF;
    for(int m = l+1; m < r; ++m){
        ret = min(ret, rec(l, m)+rec(m, r)+sm[l][r-1]);
    }

    return dp[l][r] = ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    a.resize(n);
    rep(i, n) cin >> a[i];

    sm.resize(n, vector<ll>(n, 0));
    rep(i, n){
        sm[i][i] = a[i];
        for(int j = i+1; j < n; ++j){
            sm[i][j] = sm[i][j-1] + a[j];
        }
    }

    cout << rec(0, n) << endl;

    // rep(i, n+1){
    //     rep(j, n+1) cout << dp[i][j] << " ";
    //     cout << endl;
    // }

    return 0;
}