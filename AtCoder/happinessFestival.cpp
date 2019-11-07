#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int H, W, C;
    cin >> H >> W >> C;
    int road[H][W];

    for(int i = 0; i < H; ++i){

        for(int j = 0; j < W; ++j){
            int tmp;
            cin >> tmp;
            road[i][j] = tmp;

        }
    }

    int dp[H][W] = {0};

    for(int i = 1; i < W; ++i) dp[0][i] = dp[0][i - 1] + road[0][i];

    for(int i = 1; i < H; ++i){

        for(int j = 0; j < W; ++j){

            if(j == 0) dp[i][j] = dp[i - 1][j] + road[i][j];
            else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + road[i][j];
        }
    }

    cout << dp[H - 1][W - 1] * C << endl;
}