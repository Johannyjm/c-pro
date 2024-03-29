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

    int n, m, k_;
    cin >> n >> m >> k_;
    vector<vector<int>> g(n);

    rep(i, m){
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    rep(i, n) g[i].push_back(i);

    vector<vector<mint>> dp(k_+1, vector<mint>(n, 0));
    dp[0][0] = 1;
    rep1(k, k_+1){
        mint sm = 0;
        rep(i, n){
            sm += dp[k-1][i];
        }
        rep(i, n){
            mint sub = 0;
            for(auto e: g[i]){
                sub += dp[k-1][e];
            }
            dp[k][i] = sm - sub;
        }
    }

    cout << dp[k_][0].val() << endl;

    return 0;
}