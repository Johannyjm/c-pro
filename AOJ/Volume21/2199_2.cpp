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
        vector<vector<int>> dp(n+1, vector<int>(m, INF));
        vector<int> prev(m);
        int mn = INF;
        rep(i, m) {
            dp[0][i] = pow(128+c[i]-x[0], 2);
            prev[i] = 128+c[i];
            mn = min(mn, dp[0][i]);
        }

        rep(i, m) cout << dp[0][i] << " ";
        cout << endl;
        rep(i, m) cout << prev[i] << " ";
        cout << endl;

        rep1(i, n){
            vector<int> curr(m);
            rep(j, m){
                int mn_diff = INF;
                rep(k, m){
                    int diff = pow(prev[k] + c[j] - x[i], 2);
                    if(diff < mn_diff){
                        curr[j] = prev[k] + c[j];
                        mn_diff = diff;
                        dp[i][j] = min(dp[i][j], dp[i-1][j] + diff);
                    }
                }
                
            }


            rep(j, m) cout << curr[j] << " ";
            cout << endl;
            rep(j, m) cout << dp[i][j] << " ";
            cout << endl;

            prev = curr;
        }

        // rep(i, n+1){
        //     rep(j, m) cout << dp[i][j] << " ";
        //     cout << endl;
        // }
        int res = INF;
        rep(i, m) res = min(res, dp[n-1][i]);
        cout << res << endl;

    }

    return 0;
}