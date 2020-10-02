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
    int K;
    cin >> K;

    int n = s.size();
    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(2, vector<ll>(K+5, 0)));
    dp[0][0][0] = 1;
    rep(i, n){
        int D = s[i] - '0';
        rep(j, 2){
            rep(k, 5){
                for(int d = 0; d <= (j? 9: D); ++d){
                    dp[i+1][j|(d<D)][k + (d!=0)] += dp[i][j][k];
                }
            }
        }
    }

    cout << dp[n][0][K] + dp[n][1][K] << endl;

    return 0;
}