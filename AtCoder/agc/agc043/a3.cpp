#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    rep(i, h) cin >> s[i];

    vector<vector<int>> dp(h, vector<int>(w, 0));

    dp[0][0] = 0;

    rep(i, h) rep(j, w){
        if(i==0 && j==0) continue;
        if(i==0){
            dp[i][j] = dp[i][j-1] + (s[i][j] != s[i][j-1]);
        }
        else if(j==0) dp[i][j] = dp[i-1][j] + (s[i][j] != s[i-1][j]);
        else{
            dp[i][j] = min(dp[i-1][j] + (s[i-1][j] != s[i][j]), dp[i][j-1] + (s[i][j-1] != s[i][j]));
        }
    }

    // rep(i, h) {
    //     rep(j, w) cout << dp[i][j];
    //     cout << endl;
    // }
    cout << (dp[h-1][w-1]+1)/2 + (s[0][0]=='#' && s[h-1][w-1]=='#') << endl;
    
    return 0;
}