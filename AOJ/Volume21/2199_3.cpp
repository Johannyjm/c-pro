#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int clip(int i){
    return max(0, min(255, i));
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    while(1){
        int n, m;
        cin >> n >> m;

        if(n == 0) break;

        vector<int> c(m);
        rep(i, m) cin >> c[i];

        vector<int> x(n);
        rep(i, n) cin >> x[i];

        const int INF = 1001001001;
        vector<vector<int>> dp(n, vector<int>(256, INF));
        rep(i, m) dp[0][clip(128 + c[i])] = pow(clip(128+c[i])-x[0], 2);

        rep(i, n-1){
            rep(j, 256){
                if(dp[i][j] == INF) continue;
                rep(k, m){
                    dp[i+1][clip(j+c[k])] = min(dp[i+1][clip(j+c[k])], dp[i][j] + (int)pow(clip(j+c[k])-x[i+1], 2));
                }
            }
        }

        int res = INF;
        rep(i, 256) res = min(res, dp[n-1][i]);

        cout << res << "\n";

    }

    return 0;
}