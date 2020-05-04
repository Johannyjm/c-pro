#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    vector<int> res(q);

    rep(_, q){
        string x, y;
        cin >> x >> y;
        if(y.size() > x.size()) swap(x, y);

        int n = y.size();
        int m = x.size();

        vector<vector<int>> dp(n, vector<int>(m, 0));
        if(x[0] == y[0]) dp[0][0] = 1;
        else dp[0][0] = 0;

        rep1(i, m){
            if(y[0] == x[i]) dp[0][i] = 1;
            else dp[0][i] = dp[0][i-1];
        }

        rep1(i, n){
            dp[i][0] = dp[i-1][0];
            if(y[i] == x[0]) dp[i][0] = 1;

            rep1(j, m){
                if(y[i] == x[j]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        // rep(i, n){
        //     rep(j, m) cout << dp[i][j] << " ";
        //     cout << endl;
        // }

        cout << dp[n-1][m-1] << endl;
        
    }

    return 0;
}