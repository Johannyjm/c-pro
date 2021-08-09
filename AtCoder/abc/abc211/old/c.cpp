#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

const string t = "chokudai";
mint dp[8][110000];

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int n = s.size();

    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < n; ++j){
            if(s[j] == t[i]){
                if(i == 0){
                    if(j == 0) dp[i][j] = 1;
                    else dp[i][j] = dp[i][j-1] + 1;
                }
                else{
                    if(j > 0){
                        dp[i][j] += dp[i][j-1];
                        dp[i][j] += dp[i-1][j-1];
                    }
                }
            }
            else{
                if(j > 0) dp[i][j] = dp[i][j-1];
            }
        }
    }

    cout << dp[7][n-1].val() << endl;

    return 0;
}