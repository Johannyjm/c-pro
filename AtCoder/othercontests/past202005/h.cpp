#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, l;
    cin >> n >> l;
    vector<int> x(l+1, 0);
    rep(i, n) {
        int xx;
        cin >> xx;
        x[xx] = 1;
    }
    int t1, t2, t3;
    cin >> t1 >> t2 >> t3;

    const int INF = 1001001001;
    vector<int> dp(l+1, INF);
    dp[0] = 0;
    rep1(i, l+1){
        // act1
        int act1 = dp[i-1] + t1;
        if(x[i] == 1) act1 += t3;

        // act2
        int act2 = INF;
        if(i >= 2){
            act2 = dp[i-2] + t1 + t2;
            if(x[i] == 1) act2 += t3;
        }
        
        // act3
        int act3 = INF;
        if(i >= 4){
            act3 = dp[i-4] + t1 + t2*3;
            if(x[i] == 1) act3 += t3;
        }
        dp[i] = min({act1, act2, act3});
    }

    // act3
    dp[l] = min(dp[l], dp[l-3] + t1/2 + t2*5/2);
    dp[l] = min(dp[l], dp[l-2] + t1/2 + t2*3/2);
    dp[l] = min(dp[l], dp[l-1] + t1/2 + t2/2);

    // rep(i, l+1) cout << dp[i] << " ";
    // cout << endl;
    cout << dp[l] << endl;

    return 0;
}