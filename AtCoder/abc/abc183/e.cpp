#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    vector<vector<mint>> dp(h, vector<mint>(w, 0));
    vector<vector<mint>> dps1, dps2, dps3;
    dp[0][0] = 1;
    mint smw = 1;
    mint smh = 1;
    rep1(j, w){
        if(s[0][j] == '#') break;
        dp[0][j] = smw;
        smw += dp[0][j];
    }
    rep1(i, h){
        if(s[i][0] == '#') break;
        dp[i][0] = smh;
        smh += dp[i][0];
    }

    dps1 = dp;
    dps2 = dp;
    dps3 = dp;

    rep1(i, h){
        rep1(j, w){
            if(s[i][j] == '#') continue;
            
            dp[i][j] = (s[i-1][j]!='#'? dps1[i-1][j]: 0) + (s[i][j-1]!='#'? dps2[i][j-1]: 0) + (s[i-1][j-1]!='#'? dps3[i-1][j-1]: 0);
            dps1[i][j] = (s[i-1][j]!='#'? dps1[i-1][j]: 0) + dp[i][j];
            dps2[i][j] = (s[i][j-1]!='#'? dps2[i][j-1]: 0) + dp[i][j];
            dps3[i][j] = (s[i-1][j-1]!='#'? dps3[i-1][j-1]: 0) + dp[i][j];
        }
    }

    cout << dp[h-1][w-1].val() << endl;


    return 0;
}