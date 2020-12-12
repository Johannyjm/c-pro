#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;
const int mod = 1000000007;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll h, w, k;
    cin >> h >> w >> k;

    if(w == 1){
        cout << 1 << endl;
        return 0;
    }
    
    mint dp[110][10] = {};
    dp[0][0] = 1;
    rep(i, h+1){
        rep(j, w+1){
            // down
            if(j==0 || j==w-1) dp[i+1][j] += dp[i][j] * pow_mod(2, w-2, mod);
            else dp[i+1][j] += dp[i][j] * pow_mod(2, w-3, mod);

            // left
            if(j > 0){
                mint nxt = dp[i][j];
                if(w>=4 && (j==1 || j==w-1)) nxt *= pow_mod(2, w-3, mod);
                if(w>=5 && !(j==1 || j==w-1)) nxt *= pow_mod(2, w-4, mod);
                dp[i+1][j-1] += nxt;
            }

            // right
            if(j < w-1){
                mint nxt = dp[i][j];
                if(w>=4 && (j==0 || j==w-2)) nxt *= pow_mod(2, w-3, mod);
                if(w>=5 && !(j==0 || j==w-2)) nxt *= pow_mod(2, w-4, mod);
                dp[i+1][j+1] += nxt;
            }
        }
    }


    rep(i, h+2){
        rep(j, w+2) cout << dp[i][j].val() << " ";
        cout << endl;
    }

    cout << dp[h][k-1].val() << endl;

    return 0;
}