#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int w, n, K;
    cin >> w >> n >> K;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i] >> b[i];

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(w+10, vector<int>(K+10, 0)));
    for(int j = 1; j <= w; ++j){
        if(j < a[0]) continue;
        for(int k = 1; k <= K; ++k){
            dp[0][j][k] = b[0];
        }
    }

    for(int i = 1; i < n; ++i){
        for(int j = 1; j <= w; ++j){
            for(int k = 1; k <= K; ++k){
                int cand1 = dp[i-1][j][k];
                int cand2 = dp[i][j-1][k];
                int cand3 = -1;
                if(j-a[i] >= 0) cand3 = dp[i-1][j-a[i]][k-1] + b[i];
                dp[i][j][k] = max({cand1, cand2, cand3});
            }
        }
    }

    cout << dp[n-1][w][K] << endl;

    return 0;
}
