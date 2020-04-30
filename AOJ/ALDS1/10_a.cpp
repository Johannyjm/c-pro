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

    vector<ll> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i < n+1; ++i) dp[i] = dp[i-1] + dp[i-2];

    cout << dp.back() << endl;

    return 0;
}