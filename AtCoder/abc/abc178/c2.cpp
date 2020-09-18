#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    const int mod = 1000000007;

    // long long dp[n+10][2][2] = {};
    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(2, vector<ll>(2, 0)));
    dp[0][0][0] = 8;
    dp[0][0][1] = 1;
    dp[0][1][0] = 1;
    dp[0][1][1] = 0;

    for(int i = 1; i < n+1; ++i){
        dp[i][0][0] = (dp[i-1][0][0] * 8) % mod;
        dp[i][0][1] = ((dp[i-1][0][1] * 9) % mod + dp[i-1][0][0]) % mod;
        dp[i][1][0] = ((dp[i-1][1][0] * 9) % mod + dp[i-1][0][0]) % mod;
        dp[i][1][1] = ((dp[i-1][1][1] * 10) % mod + dp[i-1][0][1]%mod + dp[i-1][1][0]%mod) % mod;
    }

    cout << (dp[n-1][1][1]) % mod << endl;

    return 0;
}
