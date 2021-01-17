#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;

mint dp[5500][5500][3];

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll h, w, k;
    cin >> h >> w >> k;
    
    vector<vector<string>> g(h, vector<string>(w, "XRD"));
    rep(i, k){
        int y, x;
        string c;
        cin >> y >> x >> c;
        --y;
        --x;
        g[y][x] = c;
    }

    // rep(i, h){
    //     rep(j, w) cout << g[i][j] << " ";
    //     cout << endl;
    // }

    rep(i, 3){
        dp[0][0][i] = mint();
    }

    mint val = 0;
    rep(i, h) rep(j, w){
        if(i==0 && j==0) continue;
        val = 0;
        if(j > 0){
            if(g[i][j-1] == "R" || g[i][j-1] == "X"){
                val += dp[i][j-1][0] + dp[i][j-1][1] + dp[i][j-1][2];
            }
            if(g[i][j-1] == "XRD"){
                val += dp[i][j-1][0] + dp[i][j-1][1];
            }
        }
        if(i > 0){
            if(g[i-1][j] == "D" || g[i-1][j] == "X"){
                val += dp[i-1][j][0] + dp[i-1][j][1] + dp[i-1][j][2];
            }
            if(g[i-1][j] == "XRD"){
                val += dp[i-1][j][0] + dp[i-1][j][2];
            }
            
        }

        rep(l, 3) dp[i][j][l] = val;
    }

    
    cout << val.val() << endl;


    return 0;
}