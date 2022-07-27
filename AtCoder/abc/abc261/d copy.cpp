#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

ll n, m;
ll x[5500], c[5500], y[5500];
unordered_map<ll, ll> cy;
ll dp[5500][5500][2];
ll dfs(int i, int j, int p){
    if(dp[i][j][p] != -1){
        return dp[i][j][p];
    }

    if(i == 1){
        if()
    }

    ll ret = 0;
    if(p == 0){
        ret = 
    }

}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    rep(i, n) cin >> x[i];
    rep(i, m) cin >> c[i] >> y[i];
    rep(i, m) cy[c[i]] = y[i];

    rep(i, 5500) rep(j, 5500) rep(k, 2) dp[i][j][k] = -1;

    ll res = 0;
    rep(j, 5500){
        if(j > i) break;
        res = max(res, dfs(n, j, 1));
    }
    cout << res << endl;

    return 0;
}