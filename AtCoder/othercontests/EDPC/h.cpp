#include <iostream>
#include <vector>
#include <string> 
using namespace std;
const int mod = 1000000007;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    
    vector<string> s(h);
    for(int i = 0; i < h; ++i) cin >> s[i];

    vector<vector<int>> dp(h, vector<int>(w, 0));
    dp[0][0] = 1;
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            if(s[i][j] == '#') continue;
            if(i > 0) dp[i][j] = (dp[i-1][j] + dp[i][j]) % mod;
            if(j > 0) dp[i][j] = (dp[i][j-1] + dp[i][j]) % mod;
        }
    }
    
    cout << dp[h-1][w-1] << endl;
    
    return 0;
}
