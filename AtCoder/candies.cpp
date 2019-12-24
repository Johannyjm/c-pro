#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int dp[2][n] = {0};

    cin >> dp[0][0];
    for (int i = 1; i < n; ++i) {
        int a1;
        cin >> a1;
        dp[0][i] = dp[0][i-1] + a1;
    }

    cin >> dp[1][0];
    dp[1][0] += dp[0][0];

    for (int i = 1; i < n; ++i){
        int a2;
        cin >> a2;
        dp[1][i] = max(dp[1][i-1] + a2, dp[0][i] + a2);
    }
    cout << dp[1][n-1] << endl;
}