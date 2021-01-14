#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int calc(int x, int nxt){
    return (x-nxt) * (x-nxt);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    const int INF = 1001001001;
    while(1){
        int n, m;
        cin >> n >> m;
        if(n == 0) break;
        vector<int> x(n);
        vector<int> c(m);
        rep(i, m) cin >> c[i];
        rep(i, n) cin >> x[i];

        vector<vector<int>> dp(n+1, vector<int>(256, INF));
        dp[0][128] = 0;
        rep(i, n){
            rep(j, 256){
                if(dp[i][j] == INF) continue;
                rep(k, m){
                    int nxt = j + c[k];
                    nxt = max(nxt, 0);
                    nxt = min(nxt, 255);

                    dp[i+1][nxt] = min(dp[i+1][nxt], dp[i][j] + calc(x[i], nxt));
                }
            }
        }

        int res = INF;
        rep(i, 256) res = min(res, dp[n][i]);
        cout << res << endl;

    }

    return 0;
}