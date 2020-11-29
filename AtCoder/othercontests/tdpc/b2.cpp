#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int dp[1100][1100];

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    rep(i, n+1) rep(j, m+1){
        if(i==0 && j==0) continue;
        else if(i == 0){
            dp[i][j] += dp[i][j-1];
            if(j%2 == 0) dp[i][j] += b[j-1];
        }
        else if(j == 0){
            dp[i][j] += dp[i-1][j];
            if(i%2 == 0) dp[i][j] += a[i-1];
        }

        else{
            if((i+j)%2 == 0){
                dp[i][j] = max(dp[i-1][j] + a[i-1], dp[i][j-1] + b[j-1]);
            }
            else{
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    rep(i, n+1){
        rep(j, m+1) cout << dp[i][j] << " ";
        cout << endl;
    }
    cout << dp[n][m] << endl;


    return 0;
}