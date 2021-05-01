#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int mod = 1000000007;
const string t = "atcoder";

long long dp[7][110000] = {};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    string s;
    cin >> n >> s;

    for(int i = 0; i < 7; ++i){
        for(int j = 0; j < n; ++j){
            if(s[j] == t[i]){
                if(j == 0)
                    dp[i][j] = 1;
                else if(i == 0){
                    dp[i][j] = dp[i][j-1] + 1;
                    dp[i][j] %= mod;
                }
                else{
                    dp[i][j] += dp[i][j-1];
                    dp[i][j] %= mod;
                    dp[i][j] += dp[i-1][j-1];
                    dp[i][j] %= mod;
                }
            }
            else{
                if(j > 0) dp[i][j] = dp[i][j-1];
            }
        }
    }

    cout << dp[6][n-1] << endl;

    return 0;
}
