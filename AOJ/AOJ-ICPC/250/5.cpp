#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int n;
vector<vector<int>>t, dp;
int rec(int s, int v){
    if(dp[s][v] != 0) return dp[s][v];
    if(s == (1<<n)-1) return 0;

    int ret = 1001001001;
    rep(nv, n){
        if(s & (1<<nv)) continue;
        int cost = t[nv][0];
        rep1(i, n+1){
            if(s & (1<<(i-1))) cost = min(cost, t[nv][i]);
        }
        ret = min(ret, rec(s|(1<<nv), nv) + cost);
    }
    
    return dp[s][v] = ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    while(1){
        cin >> n;
        if(n == 0) break;
        t.clear();
        t.resize(n, vector<int>(n+1));
        dp.clear();
        dp.resize(1<<n, vector<int>(n, 0));
        rep(i, n) rep(j, n+1) cin >> t[i][j];

        int res = 1001001001;
        rep(i, n){
            res = min(res, rec(0, i));
            
            // cout << i << endl;
            // rep(i, 1<<n){
            //     rep(j, n) cout << dp[i][j] << " ";
            //     cout << endl;
            // }
            // cout << endl;
        }
        cout << res << endl;
    }

    return 0;
}