#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int mod = 1000000007;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    string s;
    cin >> n >> s;

    vector<vector<int>> dp(7, vector<int>(n, 0));
    const string ATCODER = "atcoder";
    for(int i = 0; i < 7; ++i){
        int cnt = 1;
        for(int j = 0; j < n; ++j){
            if(s[j] == ATCODER[i]){
                if(i == 0) dp[i][j] = cnt;
                else dp[i][j] = dp[i-1][j] * cnt % mod;
                ++cnt;
            }
            else{
                if(j > 0) dp[i][j] = dp[i][j-1];
            }
        }
    }
    
    for(int i = 0; i < 7; ++i){
        for(int j = 0; j < n; ++j) cout << dp[i][j] << " ";
        cout << endl;
    }

    cout << dp[6][n-1] << endl;

    return 0;
}
