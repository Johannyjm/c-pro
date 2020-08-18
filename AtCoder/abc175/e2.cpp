#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll h, w, k;
    cin >> h >> w >> k;

    vector<vector<ll>> grid(h, vector<ll>(w));
    for(int i = 0; i < k; ++i){
        ll r, c, v;
        cin >> r >> c >> v;
        --r;
        --c;
        grid[r][c] = v;
    }

    vector<vector<vector<ll>>> dp(h, vector<vector<ll>>(w, vector<ll>(4, 0)));
    dp[0][0][1] = grid[0][0];
    for(int j = 1; j < w; ++j){
        dp[0][j][0] = dp[0][j-1][0];
        dp[0][j][1] = max(dp[0][j-1][1], dp[0][j-1][0] + grid[0][j]);
        dp[0][j][2] = max(dp[0][j-1][2], dp[0][j-1][1] + grid[0][j]);
        dp[0][j][3] = max(dp[0][j-1][3], dp[0][j-1][2] + grid[0][j]);
    }

    for(int i = 1; i < h; ++i){
        ll mx_prev0 = max({dp[i-1][0][0], dp[i-1][0][1], dp[i-1][0][2], dp[i-1][0][3]});
        dp[i][0][0] = mx_prev0;
        dp[i][0][1] = mx_prev0 + grid[i][0];
        for(int j = 1; j < w; ++j){
            ll mx_prev = max({dp[i-1][j][0], dp[i-1][j][1], dp[i-1][j][2], dp[i-1][j][3]});
            dp[i][j][0] = max(mx_prev, dp[i][j-1][0]);
            dp[i][j][1] = max({mx_prev + grid[i][j], dp[i][j-1][1], dp[i][j-1][0] + grid[i][j]});
            dp[i][j][2] = max(dp[i][j-1][2], dp[i][j-1][1] + grid[i][j]);
            dp[i][j][3] = max(dp[i][j-1][3], dp[i][j-1][2] + grid[i][j]);
        }
    }

    cout << max({dp[h-1][w-1][0], dp[h-1][w-1][1], dp[h-1][w-1][2], dp[h-1][w-1][3]}) << endl;

    return 0;
}
