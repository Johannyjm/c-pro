#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

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
        vector<vector<int>> dp(n+2, vector<int>(m, INF));
        rep(i, m) dp[0][i] = 128;

        int res = 0;
        rep1(i, n+2){
            int gmn = INF;
            rep(j, m) {
                int mn = INF;
                rep(k, m){
                    int val = max(0, min(255, dp[i-1][k] + c[j]));

                    int diff = (x[i-1]-val) * (x[i-1]-val);
                    if(diff < mn){
                        mn = diff;
                        dp[i][j] = val;
                    }
                }

                gmn = min(gmn, mn);
                cout << gmn << endl;
            }
            res += gmn;
        }

        rep(i, n+2) {
            rep(j, m) cout << dp[i][j] << " ";
            cout << endl;
        }

        cout << res << endl;
    }

    return 0;
}