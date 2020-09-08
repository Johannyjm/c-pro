#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<string> s(5);
    rep(i, 5) cin >> s[i];

    const int INF = 1001001001;
    char colors[3] = {'R', 'B', 'W'};
    vector<vector<int>> dp(n, vector<int>(3, INF)); // n: col, 3: required changes to R, B, W
    rep(c, 3){
        int sm = 0;
        rep(r, 5){
            if(s[r][0] != colors[c]) ++sm;
        }
        dp[0][c] = sm;
    }

    rep1(i, n){
        vector<int> changes(3, 0); // to R, B, W;
        rep(c, 3){
            rep(r, 5){
                if(s[r][i] != colors[c]) ++changes[c];
            }
        }

        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + changes[0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + changes[1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + changes[2];

    }

    cout << min({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;




    return 0;
}