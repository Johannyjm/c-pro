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
    rep(i, h){
        rep(j, w){
            mint nxt_l = 0;
            mint nxt_d = 0;
            mint nxt_r = 0;

            rep(bit, 1<<(w-1)){
                vector<int> use(w-1, 0);
                rep(k, w-1){
                    if(bit & (1<<k)){
                        use[k] = 1;
                    }
                }
                
                bool valid = true;
                rep(k, w-2){
                    if(use[k]==1 && use[k+1]==1){
                        valid = false;
                        break;
                    }
                }
                if(!valid) continue;

                if(j-1>=0 && use[j-1]==1) ++nxt_l;
                else if(j<w-1 && use[j]==1) ++nxt_r;
                else ++nxt_d;
            }

            dp[i+1][j] += dp[i][j] * nxt_d;
            if(j > 0) dp[i+1][j-1] += dp[i][j] * nxt_l;
            if(j < w-1) dp[i+1][j+1] += dp[i][j] * nxt_r;
        }
    }


    // rep(i, h+1){
    //     rep(j, w+1) cout << dp[i][j].val() << " ";
    //     cout << endl;
    // }

    cout << dp[h][k-1].val() << endl;

    return 0;
}