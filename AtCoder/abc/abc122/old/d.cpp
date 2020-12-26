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

    int n;
    cin >> n;

    mint dp[110][4][4][4] = {};
    dp[3][0][1][2] = 1;
    dp[3][0][2][1] = 1;
    dp[3][1][0][2] = 1;

    string s[] = {"A", "G", "C", "T"};
    
    for(int d = 3; d < n; ++d){
        rep(i, 4) rep(j, 4) rep(k, 4) rep(l, 4){

            
        //     rep(l, 4){
        //         inc[j][k][l] += dp[d][i][j][k];
        //         bool flg = false;
        //         if((j==0&&k==1&&l==2)
        //         || (j==0&&k==2&&l==1)
        //         || (j==1&&k==0&&l==2) 
        //         || (i==0&&j==1&&k!=2&&l==2)
        //         || (i==0&&j!=0&&k==1&&l==2)){
        //             ++inc[j][k][l];
        //             string before = s[i] + s[j] + s[k];
        //             string after = s[i] + s[j] + s[k] + s[l];
        //             cout << before << " -inc> " << after << " " << dp[d][i][j][k].val() << "->" << endl;
        //             flg = true;
        //         }

        //         if(!flg && inc[j][k][l].val() > 0){
        //             string before = s[i] + s[j] + s[k];
        //             string after = s[i] + s[j] + s[k] + s[l];
        //             cout << before << " -> " << after << endl;
        //         }
        //     }
        // }
        // rep(i, 4) rep(j, 4) rep(k, 4){
        //     dp[d+1][i][j][k] += inc[i][j][k];
        // }
    }

    mint res = 4;
    res = res.pow(n);
    rep(i, 4) rep(j, 4) rep(k, 4) res -= dp[n][i][j][k];

    cout << res.val() << endl;

    return 0;
}