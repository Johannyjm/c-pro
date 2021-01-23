#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n)), dp(2, vector<int>(n, 0));
    rep(i, 2) rep(j, n) cin >> a[i][j];
    
    dp[0][0] = a[0][0];
    rep(i, 2) rep(j, n){
        if(i==0 && j==0) continue;
        if(i > 0) dp[i][j] = max(dp[i][j], dp[i-1][j] + a[i][j]);
        if(j > 0) dp[i][j] = max(dp[i][j], dp[i][j-1] + a[i][j]);
    }

    cout << dp[1][n-1] << endl;

    return 0;
}