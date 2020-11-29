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
    rep(j, m) cin >> b[j];

    for(int i = n; i >= 0; --i){
        for(int j = m; j >= 0; --j){
            if(i==n && j==m) continue;

            if((i+j)%2 == 0){
                if(i == n){
                    dp[i][j] = dp[i][j+1] + b[j];
                }
                else if(j == m){
                    dp[i][j] = dp[i+1][j] + a[i];
                }
                else{
                    dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j+1] + b[j]);
                }
            }
            else{
                if(i == n){
                    dp[i][j] = dp[i][j+1];
                }
                else if(j == m){
                    dp[i][j] = dp[i+1][j];
                }
                else{
                    dp[i][j] = min(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
    }

    cout << dp[0][0] << endl;

    return 0;
}