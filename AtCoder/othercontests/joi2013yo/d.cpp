#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int d, n;
    cin >> d >> n;

    vector<int> t(d);
    rep(i, d) cin >> t[i];
    vector<int> a(n), b(n), c(n);
    rep(i, n) cin >> a[i] >> b[i] >> c[i];

    vector<vector<int>> dp(d, vector<int>(n, 0));
    vector<int> prev(n, -1);
    rep(i, n){
        if(a[i]<=t[0] && t[0]<=b[i]) prev[i] = c[i];
    }
    rep1(i, d){
        vector<int> curr(n, -1);
        rep(j, n){
            if(a[j]<=t[i] && t[i]<=b[j]) curr[j] = c[j];
        }

        rep(j, n) rep(k, n){
            if(prev[k]==-1 || curr[j]==-1) continue;
            dp[i][j] = max(dp[i][j], dp[i-1][k] + abs(prev[k] - curr[j]));
        }
        prev = curr;

        // cout << endl;
        // rep(j, d){
        //     rep(k, n) cout << dp[j][k] << " ";
        //     cout << endl;
        // }
    }

    int res = 0;
    rep(i, n) res = max(res, dp[d-1][i]);
    
    cout << res << endl;

    return 0;
}