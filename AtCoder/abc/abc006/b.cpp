#include <iostream>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int dp[n+1] = {};
    dp[3] = 1;
    for(int i = 4; i <= n; ++i){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        dp[i] %= 10007;
    }

    cout << dp[n] << endl;

    return 0;
}
