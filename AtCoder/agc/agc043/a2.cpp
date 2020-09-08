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

    int res = 500;

    rep(r, h) rep(c, w){
        vector<vector<int>> dp(h, vector<int>(w, 0));

        if(s[0][0]=='#'&&) dp[0][0] = 1;
        else dp[0][0] = 0;

        rep(i, h) rep(j, w){
            if(i==0 && j==0) continue;
            if(i==0){
                dp[i][j] = dp[i][j-1] + (s[i][j]=='#');
            }
            else if(j==0) dp[i][j] = dp[i-1][j] + (s[i][j] == '#');
            else{
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + (s[i][j] == '#');
            }
        }

        res = min(res, dp[h-1][w-1]);
    }

    cout << res << endl;
    return 0;
}