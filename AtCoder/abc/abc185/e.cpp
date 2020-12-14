#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    const int INF = 1001001001;
    vector<vector<int>> dp(1100, vector<int>(1100, INF));

    rep(i, n) dp[i][0] = i;
    rep(j, m) dp[0][j] = j;

    rep1(i, n+1) rep1(j, m+1){
        int cost = 1;
        if(a[i-1] == b[j-1]) cost = 0;
        dp[i][j] = min({dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+cost});
    }

    cout << dp[n][m] << endl;

    return 0;
}