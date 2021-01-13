#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int st;
vector<ll> a;
vector<vector<int>> g;
vector<bool> seen;
vector<ll> dp;

void dfs(int v, ll prev, ll cmn){
    seen[v] = true;

    if(v != st) dp[v] = max({prev, dp[v], a[v] - cmn});
    cmn = min(cmn, a[v]);

    for(auto nv: g[v]){
        // if(seen[nv]) continue;

        dfs(nv, dp[v], cmn);
    }
}


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    a.resize(n);
    rep(i, n) cin >> a[i];
    g.resize(n);
    rep(i, m){
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        g[x].push_back(y);
    }

    seen.resize(n, false);
    dp.resize(n, -1001001001);

    st = 0;
    while(st != n){
        if(g[st].size()==0 || seen[st]){
            ++st;
            continue;
        }

        dfs(st, -1001001001, 1001001001);
        ++st;
    }

    // for(auto e: dp) cout << e << " ";
    // cout << endl;

    ll res = -1001001001;
    rep(i, n){
        res = max(res, dp[i]);
    }

    cout << res << endl;

    return 0;
}