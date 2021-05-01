#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    string s;
    cin >> n >> s;
    
    const string t = "atcoder";
    mint dp[7][110000];
    rep(i, 7){
        rep(j, n){
            if(s[j] == t[i]){
                if(i == 0){
                    if(j == 0) dp[i][j] = 1;
                    else dp[i][j] = dp[i][j-1] + 1;
                }
                else{
                    if(j > 0) dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                }
            }
            else{
                if(j > 0) dp[i][j] += dp[i][j-1];
            }
        }
    }

    // rep(i, 7){
    //     rep(j, n) cout << dp[i][j].val() << " ";
    //     cout << endl;
    // }

    cout << dp[6][n-1].val() << endl;

    return 0;
}