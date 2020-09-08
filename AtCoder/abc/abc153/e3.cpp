#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, n;
    cin >> h >> n;
    vector<pair<int, int>> ab(n);
    rep(i, n){
        int a, b;
        cin >> a >> b;
        ab[i] = make_pair(a, b);
    }

    vector<vector<int>> dp(n, vector<int>(h+1, 0));

    rep(j, h+1){
        int a = ab[0].first;
        int b = ab[0].second;

        dp[0][j] = b * ((j+a-1) / a);
    }

    rep1(i, n){
        int a = ab[i].first;
        int b = ab[i].second;

        rep(j, h+1){
            if(j<=a) dp[i][j] = min(dp[i-1][j], b);
            else dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-a]+b, b * ((j+a-1) / a)));
        }
    }

    // rep(j, h+1){
    //     cout << dp[n-1][j] << " ";
    // }
    cout << endl;

    cout << dp[n-1][h] << endl;

    return 0;
}