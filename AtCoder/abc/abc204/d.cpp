#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int dp[110][110000];

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> t(n);
    int sm = 0;
    rep1(i, n+1){
        cin >> t[i];
        sm += t[i];
    }

    dp[0][0] = 1;
    rep1(i, n+1){
        rep(j, 110000){
            dp[i][j] = dp[i-1][j];
            if(j-t[i] >= 0){
                if(dp[i-1][j-t[i]] > 0) dp[i][j] = dp[i-1][j-t[i]];
            }
        }
    }

    int res = 1001001001;
    rep(j, 110000){
        if(dp[n][j]>0){
            int one = j;
            int theother = sm-j;

            res = min(res, max(one, theother));
        }
    }
    cout << res << endl;

    return 0;
}