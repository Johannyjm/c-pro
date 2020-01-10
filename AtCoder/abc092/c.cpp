#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    // vector<int> a(n+2);
    // vector<int, int> dp(2)(n+2);
    
    int a[n+2], dp[2][n+2];

    a[0] = 0;
    a[n+1] = 0;
    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[1][1] = 0;

    rep1(i, n+2){
        if(i<n+1) cin >> a[i];

        dp[0][i] = dp[0][i-1] + abs(a[i] - a[i-1]);
        if(i>1) dp[1][i] = dp[0][i-2] + abs(a[i] - a[i-2]);
    }

    rep(i, n+2) cout << dp[0][i] << " ";
    cout << endl;
    rep(i, n+2) cout << dp[1][i] << " ";
    cout << endl;

    for (int i = 2; i < n+2; ++i){
        cout << dp[0][n+1] - (dp[0][i] - dp[1][i]) << endl;
    }
}