#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, k, s, t, x;
    cin >> n >> m >> k >> s >> t >> x;
    --s;
    --t;
    --x;

    vector<vector<int>> g(n);
    rep(i, m){
        int u, v;
        cin >> u >> v;
        --u;
        --v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<vector<pair<mint, mint>>> dp(k+10, vector<pair<mint, mint>>(n, pair<mint, mint>({0, 0})));
    dp[0][s] = {1, 0};
    rep1(i, k+1){
        rep(j, n){
            if(dp[i-1][j].first.val() == 0 && dp[i-1][j].second.val() == 0) continue;

            for(int nv: g[j]){
                if(nv == x){
                    dp[i][nv].first += dp[i-1][j].second;
                    dp[i][nv].second += dp[i-1][j].first;
                }
                else{
                    dp[i][nv].first += dp[i-1][j].first;
                    dp[i][nv].second += dp[i-1][j].second;   
                }
            }
        }
    }

    mint res = dp[k][t].first;
    cout << res.val() << endl;



    return 0;
}