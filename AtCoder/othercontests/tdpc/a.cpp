#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int dp[110][11000];

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> p(n);
    rep1(i, n+1) cin >> p[i];

    dp[0][0] = 1;
    rep1(i, n+1){
        rep(j, 11000){
            dp[i][j] = dp[i-1][j];
            if(j-p[i] >= 0){
                if(dp[i-1][j-p[i]] > 0) dp[i][j] = dp[i-1][j-p[i]];
            }
        }
    }

    int res = 0;
    rep(i, 11000) if(dp[n][i]>0) ++res;
    cout << res << endl;

    return 0;
}