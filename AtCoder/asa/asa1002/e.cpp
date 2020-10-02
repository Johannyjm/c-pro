#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    string s;
    cin >> s;

    vector<vector<ll>> dp(n+1, vector<int>(n+1, 0));
    rep1(i, n+1) rep1(j, n+1){
        if(s[i-1] == s[j-1]){
            if(i!=j && dp[i-1][j-1]+1 <= j-i){
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            }
        }
        dp[i][j] = max({dp[i][j], dp[i-1][j], dp[i][j-1]});
    }

    // rep(i, n+1){
    //     rep(j, n+1) cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    cout << dp[n][n] << endl;

    return 0;
}