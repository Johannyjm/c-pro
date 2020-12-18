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

    string s;
    cin >> s;
    int n = s.size();

    mint dp[110000][13] = {};

    rep(i, n){
        
        if(i == 0){
            if(s[i] == '?'){
                rep(j, 10) dp[0][j] = 1;
            }
            else{
                int d = s[i] - '0';
                dp[0][d] = 1;
            }
            continue;
        }

        rep(j, 13){
            if(s[i] == '?'){
                rep(d, 10){
                    dp[i][((j*10)+d) % 13] += dp[i-1][j];
                }
            }
            else{
                int d = s[i] - '0';
                dp[i][((j*10)+d) % 13] += dp[i-1][j];
            }
        }
        
    }

    cout << dp[n-1][5].val() << endl;

    return 0;
}