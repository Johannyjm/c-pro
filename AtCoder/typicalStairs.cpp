#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int dp[n+1] = {0};
    
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        dp[a] = -1;
    }
    dp[0] = 1;
    if(dp[1] != -1) dp[1] = 1;

    int MOD = 1000000007;

    for (int i = 2; i < n+1; ++i){
        if(dp[i] == -1) continue;

        if(dp[i-2] != -1 && dp[i-1] != -1) dp[i] = (dp[i-2]%MOD + dp[i-1]%MOD)%MOD;
        if(dp[i-2] == -1 && dp[i-1] != -1) dp[i] = dp[i-1];
        if(dp[i-2] != -1 && dp[i-1] == -1) dp[i] = dp[i-2];
        if(dp[i-2] == -1 && dp[i-1] == -1) dp[i] = 0;
    }
    for(int i = 0; i < n+1; ++i) cout << dp[i] << " ";
    cout << dp[n] << endl;
}