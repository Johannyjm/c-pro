#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, t;
    cin >> n >> t;
    vector<pair<int, int>> ab(n);
    rep(i, n) cin >> ab[i].first >> ab[i].second;

    sort(ab.begin(), ab.end());
    // cout << endl;
    // rep(i, n) cout << ab[i].first << " " << ab[i].second << endl;

    int a_mx = ab.back().first;
    // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(t+10, vector<int>(2, 0)));
    int dp[n+1][t+a_mx] = {};
    rep(j, t+a_mx){
        if(j >= ab[0].first) dp[0][j] = ab[0].second; 
    }

    int res = dp[0][t-1] + ab[1].second;
    rep1(i, n-1){
        dp[i][0] = dp[i-1][0];
        rep1(j, t+a_mx){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if(j-ab[i].first >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-ab[i].first] + ab[i].second);
        }

        res = max(res, dp[i][t-1] + ab[i+1].second);
    }
    // rep(i, n){
    //     rep(j, t+a_mx) cout << j << ":" << dp[i][j] << ", ";
    //     cout << endl;
    // }

    cout << res << endl;

    return 0;
}