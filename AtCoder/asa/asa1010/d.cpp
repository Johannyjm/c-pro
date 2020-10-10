#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int n = s.size();

    int dp[n+1][2][2][2][2] = {};
    dp[0][0][0][0][0] = 1;
    rep(i, n){
        int D = s[i]-'0';
        rep(j, 2) rep(k, 2) rep(l, 2) rep(m, 2){
            for(int d = 3; d <= (j? 7: D); d+=2){
                dp[i+1][j|(d<D)][k|(d==3)][l|(d==5)][m|(d==7)] += dp[i][j][k][l][m];
            }
        }
    }

    cout << dp[n][0][1][1][1] + dp[n][1][1][1][1] << endl;


    return 0;
}