#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    const int INF = 1001001001;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(330, vector<int>(330, INF)));

    rep(j, a[0]+1) rep(k, b[0]+1) dp[0][j][k] = 1;
    rep1(i, n){
        rep(j, 330){
            rep(k, 330){
                if(j-a[i] >= 0 && k-b[i] >= 0 && dp[i-1][j-a[i]][k-b[i]] != INF){
                    dp[i][j][k] = min(dp[i][j][k], dp[i-1][j-a[i]][k-b[i]] + 1);
                }
            }
        }
        rep(j, a[i]+1) rep(k, b[i]+1) dp[i][j][k] = 1;

        for(int j = 329; j > 0; --j){
            for(int k = 329; k > 0; --k){
                dp[i][j-1][k] = min(dp[i][j-1][k], dp[i][j][k]);
                dp[i][j][k-1] = min(dp[i][j][k-1], dp[i][j][k]);
            }
        }
    }

    // rep(i, n){
    //     rep(j, 10){
    //         rep(k, 10) cout << dp[i][j][k] << " ";
    //         cout << endl;
    //     }
    //     cout << endl;
    // }

    int res = dp[n-1][x][y];
    
    if(res == INF) res = -1;

    cout << res << endl;


    return 0;
}