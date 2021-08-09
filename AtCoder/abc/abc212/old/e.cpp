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

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<bool>> g(n, vector<bool>(n, true));
    rep(i, m){
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u][v] = false;
        g[v][u] = false;
    }
    
    vector<mint> dp(n, 0);
    dp[0] = 1;
    vector<bool> nxt(n, false);
    nxt[0] = true;

    rep(_, k){
        vector<bool> nxtmp(n, false);
        vector<mint> tmp(n, 0);    
        rep(v, n){
            if(!nxt[v]) continue;

            vector<mint> sm(n, 0);
            rep(nv, n){
                if(!g[v][nv]) continue;
                if(v == nv) continue;
                
                sm[nv] += dp[v];
                nxtmp[nv] = true;
            }

            rep(i, n) tmp[i] += sm[i];
        }
        nxt = nxtmp;
        dp = tmp;
    }

    cout << dp[0].val() << endl;
    
    

    return 0;
}