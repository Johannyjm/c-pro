#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll h, w, k;
    cin >> h >> w >> k;

    vector<vector<ll>> grid(h, vector<ll>(w, 0));
    ll r, c, v;
    for(int i = 0; i < k; ++i){
        cin >> r >> c >> v;
        --r;
        --c;
        grid[r][c] = v;
    }

    vector<vector<ll>> dp(h, vector<ll>(w, 0));
    dp[0][0] = grid[0][0];
    for(int i = 1; i < h; ++i){
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }

    for(int i = 0; i < h; ++i){
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        if(grid[i][0] != 0) pq.push(grid[i][0]);
        
        for(int j = 1; j < w; ++j){
            if(i == 0){
                if(grid[i][j] == 0) dp[i][j] = dp[i][j-1];
                else if(pq.size() < 3){
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                    pq.push(grid[i][j]);
                }
                else{
                    ll mn = pq.top();
                    if(mn >= grid[i][j]) dp[i][j] = dp[i][j-1];
                    else{
                        pq.pop();
                        dp[i][j] = dp[i][j-1] - mn + grid[i][j];
                        pq.push(grid[i][j]);
                    }
                }
            }
            else{
                if(grid[i][j] == 0) dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                else if(pq.size() < 3){
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
                    if(dp[i-1][j] >= dp[i][j-1]){
                        while(!pq.empty()) pq.pop();
                    }
                    pq.push(grid[i][j]);
                }
                else{
                    ll mn = pq.top();
                    if(mn >= grid[i][j]) dp[i][j] =  max(dp[i-1][j], dp[i][j-1]);
                    else{
                        pq.pop();
                        dp[i][j] = max(dp[i][j-1] - mn, dp[i-1][j]) + grid[i][j];
                        if(dp[i-1][j] >= dp[i][j-1]){
                            while(!pq.empty()) pq.pop();
                        }
                        pq.push(grid[i][j]);
                    }
                }
            }
        }
    }

    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << dp[h-1][w-1] << endl;


    return 0;
}
