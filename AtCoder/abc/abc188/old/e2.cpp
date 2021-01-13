#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;


vector<ll> a;
vector<vector<int>> g;
vector<bool> seen;
vector<ll> dp, mn;

void dfs(int v){
    seen[v] = true;

    for(auto nv: g[v]){
        mn[nv] = min({mn[v], mn[nv], a[nv]});
        dp[nv] = max(dp[v], a[nv]-mn[v]);
        if(seen[nv]) continue;
        dfs(nv);
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

    dp.resize(n, -1001001001);
    mn.resize(n, 1001001001);

    int st = 0;
    seen.resize(n, false);
    while(st != n){
        if(g[st].size() == 0 || seen[st]){
            ++st;
            continue;
        }
        mn[st] = a[st];
        dfs(st);
        ++st;
    }

    ll res = -1001001001;
    rep(i, n) res = max(res, dp[i]);

    cout << res << endl;

    return 0;
}