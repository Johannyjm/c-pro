#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;


ll n;
ll a[2200];
ll dp[2200][2200][2];
ll cnv(ll i){
    if(i < 0) return n-1;
    else if(i >= n) return 0;
    else return i;
}

ll solve(ll l, ll r, ll turn = 1, ll cnt = 1){
    if(cnt == n) return 0;
    if(dp[l][r][turn] >= 0) return dp[l][r][turn];

    if(turn == 1){
        ll ret;
        if(a[cnv(l-1)] > a[cnv(r+1)]) ret = solve(cnv(l-1), r, 0, cnt+1);
        else ret = solve(l, cnv(r+1), 0, cnt+1);

        dp[l][r][turn] = ret;
        return ret;
    }
    else{
        ll ret = max(solve(cnv(l-1), r, 1, cnt+1) + a[cnv(l-1)], solve(l, cnv(r+1), 1, cnt+1) + a[cnv(r+1)]);
        dp[l][r][turn] = ret;
        return ret;
    }

}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;

    rep(i, n) cin >> a[i];

    rep(i, 2200) rep(j, 2200) rep(k, 2){
        dp[i][j][k] = -1;
    }

    ll res = 0;
    rep(i, n){
        res = max(res, solve(i, i) + a[i]);
    }

    cout << res << endl;

    return 0;
}