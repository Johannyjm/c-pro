#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    ll dp[n][2] = {0};
    int c0 = s[0] - '0';
    dp[0][0] = c0;
    dp[0][1] = 1;

    rep1(i, n){
        int c = s[i] - '0';
        dp[i][0] = dp[i-1][0] * 10 + dp[i-1][1] * c;
        dp[i][1] = dp[i-1][0] * 0 + dp[i-1][1] * 1;
    }

    rep(i, n){
        rep(j, 2){
            cout << dp[i][j] << " ";
        }
        cout << endl;

    }

    cout << endl << dp[n-1][0] + dp[n-1][1] << endl;

    return 0;
}