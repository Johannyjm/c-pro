#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> d(n), c(m);
    rep(i, n) cin >> d[i];
    rep(i, m) cin >> c[i];

    int max_stay = m-n;
    const int INF = 1001001001;

    vector<vector<int>> dp(n+1, vector<int>(max_stay+1, INF));
    rep(i, max_stay+1) dp[0][i] = 0;

    rep1(i, n+1){
        rep(j, max_stay+1){
            if(j==0 || i==1) dp[i][j] = dp[i-1][j] + c[i+j-1]*d[i-1];
            else{
                for(int k = 0; k <= j; ++k){
                    dp[i][j] = min(dp[i][j], dp[i-1][k]+c[i+j-1]*d[i-1]);
                }
            }
        }

    }

    int res = INF;
    rep(i, max_stay+1) res = min(res, dp[n][i]);
    
    cout << res << endl;

    return 0;
}