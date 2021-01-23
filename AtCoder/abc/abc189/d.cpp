#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<ll>> dp(66, vector<ll>(2, 0));
    dp[0][0] = 1;
    dp[0][1] = 1;
    rep1(i, n+1){
        string s;
        cin >> s;

        if(s == "AND"){
            dp[i][0] += dp[i-1][0];
            dp[i][1] += dp[i-1][0] + dp[i-1][1]*2;
        }
        else{
            dp[i][0] += dp[i-1][0]*2 + dp[i-1][1];
            dp[i][1] += dp[i-1][1];
        }
    }

    cout << dp[n][0] << endl;


    return 0;
}