#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;

mint dp[5500][5500];

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll h, w, k;
    cin >> h >> w >> k;
    
    vector<vector<int>> g(h, vector<int>(w, -1));
    rep(i, k){
        int y, x;
        char c;
        cin >> y >> x >> c;
        --y;
        --x;
        g[y][x] = c - 'A';
    }

    // rep(i, h){
    //     rep(j, w) cout << g[i][j] << " ";
    //     cout << endl;
    // }

    dp[0][0] = mint(3).pow(h*w - k);
    mint val = 2 * (mint(3).inv());

    rep(i, h) rep(j, w){
        if(i==0 && j==0) continue;
        if(j > 0){
            if(g[i][j-1] == 'R'-'A' || g[i][j-1] == 'X'-'A'){
                dp[i][j] += dp[i][j-1];
            }
            if(g[i][j-1] == -1){
                dp[i][j] += dp[i][j-1] * val;
            }
        }
        if(i > 0){
            if(g[i-1][j] == 'D'-'A' || g[i-1][j] == 'X'-'A'){
                dp[i][j] += dp[i-1][j];
            }
            if(g[i-1][j] == -1){
                dp[i][j] += dp[i-1][j] * val;
            }
            
        }
    }

    // rep(i, h){
    //     rep(j, w) cout << dp[i][j].val() << " ";
    //     cout << endl;
    // }
    
    cout << dp[h-1][w-1].val() << endl;


    return 0;
}