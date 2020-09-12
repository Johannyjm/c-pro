#include <iostream>
#include <vector>
#include <string>
using namespace std;

int dp[32][2][32];

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    // if(s[0]=='1') dp[1][0][1] = 1;
    // else dp[1][1][0] = 1;
    dp[0][0][0] = 1;

    for(int i = 0; i < n; ++i){
        int D = s[i] - '0';
        for(int j = 0; j < 2; ++j){
            for(int k = 0; k < n+1; ++k){
                for(int d = 0; d <= (j? 9: D); ++d){
                    dp[i+1][j||(d<D)][k+(d==1)] += dp[i][j][k];
                }
            }
        }
    }

    int res = 0;
    for(int i = 0; i < n+1; ++i) res += (dp[n][0][i] + dp[n][1][i]) * i;

    cout << res << endl;

    return 0;
}
