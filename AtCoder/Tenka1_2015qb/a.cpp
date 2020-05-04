#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<int> dp(20, 0);
    dp[0] = 100;
    dp[1] = 100;
    dp[2] = 200;

    for(int i = 3; i < 20; ++i) dp[i] = dp[i-1] + dp[i-2] + dp[i-3];

    cout << dp[19] << endl;

    return 0;
}