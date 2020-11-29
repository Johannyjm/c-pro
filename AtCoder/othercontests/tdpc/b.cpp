#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int dp[1100][1100][2];

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    rep(i, n+1) rep(j, m+1){
        if(i == 0 && j == 0) continue;
        else if(i == 0){
            dp[i][j][0] += dp[i][j-1][0];
            dp[i][j][1] += dp[i][j-1][1];
            if(j%2 == 1) dp[i][j][0] += b[j-1];
            else dp[i][j][1] += b[j-1];
        }
        else if(j == 0){
            dp[i][j][0] += dp[i-1][j][0];
            dp[i][j][1] += dp[i-1][j][1];
            if(i%2 == 1) dp[i][j][0] += a[i-1];
            else dp[i][j][1] += a[i-1];
        }

        else{
            if((i+j)%2 == 1){
                int dp1 = dp[i-1][j][0] + a[i-1] - dp[i-1][j][1];
                int dp2 = dp[i][j-1][0] + b[j-1] - dp[i][j-1][1];
                
                if(dp1 < dp2){
                    dp[i][j][0] = dp[i][j-1][0] + b[j-1];
                    dp[i][j][1] = dp[i][j-1][1];
                }
                else{
                    dp[i][j][0] = dp[i-1][j][0] + a[i-1];
                    dp[i][j][1] = dp[i-1][j][1];
                }
            }
            else{
                int dp1 = dp[i-1][j][1] + a[i-1] - dp[i-1][j][0];
                int dp2 = dp[i][j-1][1] + b[j-1] - dp[i][j-1][0];

                if(dp1 < dp2){
                    dp[i][j][1] = dp[i][j-1][1] + b[j-1];
                    dp[i][j][0] = dp[i][j-1][0];
                }
                else{
                    dp[i][j][1] = dp[i-1][j][1] + a[i-1];
                    dp[i][j][0] = dp[i-1][j][0]; 
                }
            }
        }
    }

    cout << dp[n][m][0] << endl;

    rep(i, n+1){
        rep(j, m+1) cout << dp[i][j][0] << " ";
        cout << endl;
    }
    cout << endl;
    rep(i, n+1){
        rep(j, m+1) cout << dp[i][j][1] << " ";
        cout << endl;
    }

    return 0;
}