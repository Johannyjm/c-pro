#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

vector<int> g;
vector<vector<double>> dp;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    
    while(1){
        int n, t, l, b;
        cin >> n >> t >> l >> b;

        if(n == 0) break;

        g.clear();
        g.resize(n+1, 0);
        rep(i, l){
            int lose;
            cin >> lose;
            g[lose] = 1;
        }
        rep(i, b){
            int back;
            cin >> back;
            g[back] = 2;
        }

        dp.clear();
        dp.resize(110, vector<double>(110, 0));

        dp[0][0] = 1.0;
        double res = 0.0;
        rep(i, t){
            rep(now, n){
                for(int gain = 1; gain <= 6; ++gain){
                    int nxt = now + gain;
                    if(nxt > n) nxt = n - (nxt-n);
                    if(g[nxt] == 2) nxt = 0;

                    if(g[nxt] == 1) dp[i+2][nxt] += dp[i][now] / 6;
                    else dp[i+1][nxt] += dp[i][now] / 6;

                    if(nxt == n) res += dp[i][now] / 6;
                }
            }
        }

        // rep(i, 7){
        //     rep(j, 7) cout << dp[i][j] << " ";
        //     cout << endl;
        // }

        // cout << setprecision(6);
        // cout << res << endl;

        printf("%.6f\n", res);
    }

    return 0;
}