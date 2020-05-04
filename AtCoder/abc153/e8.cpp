#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, n;
    cin >> h >> n;

    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    const int INF = 1001001001;
    vector<int> dp(22000, INF);
    dp[0] = 0;
    rep1(i, 22000){
        rep(j, n){
            if(a[j] <= i) dp[i] = min(dp[i], dp[i-a[j]] + b[j]);
        }
    }

    int res = INF;
    for(int i = h; i < 22000; ++i) res = min(res, dp[i]);

    cout << res << endl;

    return 0;
}