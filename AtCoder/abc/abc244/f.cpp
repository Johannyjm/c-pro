#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> bits(n);
    int bitcnt = 0;
    int res = n;
    rep(i, 1<<n){
        bitcnt = 0;
        rep(j, n){
            if(i & (1<<j)){
                bits[j] = 1;
                ++bitcnt;
            }
            else bits[j] = 0;
        }

        if(bitcnt < 2) continue;

        rep(st, n){
            vector<int> dp(n, 0);
            vector<int> cand;
            dp[st] = 1;

            rep(k, 100){
                vector<int> nxt(n, 0);
                rep(v, n){
                    if(dp[v] == 0) continue;
                    for(int nv: g[v]){
                        nxt[nv] += dp[v];
                    }
                }
                dp = nxt;

                vector<int> mod2(n);
                rep(v, n) mod2[v] = dp
            }

            
        }
    }


    return 0;
}