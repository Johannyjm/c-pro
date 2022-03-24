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
    vector<vector<vector<int>>> dp(330, vector<vector<int>>(330, vector<int>(330, INF)));
    dp[0][0][0] = 0;

    rep(i, n+1){
        rep(j, 330) rep(k, 330) if(dp[i][j][k] < INF) {
            dp[i+1][min(j+a[i], x)][min(k+b[i], y)] = min(dp[i+1][min(j+a[i], x)][min(k+b[i], y)], dp[i][j][k] + 1);
            dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
        }
    }

    int res = dp[n][x][y];

    if(res == INF) res = -1;
    
    cout << res << endl;

    return 0;
}