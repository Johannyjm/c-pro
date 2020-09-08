#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> dp(n, 0);
    dp[0] = 0;
    dp[1] = dp[0] + abs(a[1] - a[0]);

    for (int i = 2; i < n; ++i){
        dp[i] = min(dp[i-2] + abs(a[i]-a[i-2]), dp[i-1] + abs(a[i]-a[i-1]));
    }

    cout << dp[n-1] << endl;

    return 0;
}