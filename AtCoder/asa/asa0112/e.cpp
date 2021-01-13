#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

vector<ll> a;
vector<vector<int>> g;
vector<bool> seen;
vector<ll> mx, mn;

void dfs(int v, ll cmx, ll cmn){
    seen[v] = true;

    mx[v] = max(cmx, a[v]);
    mn[v] = min(cmn, a[v]);

    for(auto nv: g[v]){
        if(seen[nv]) continue;

        dfs(nv, mx[v], mn[v]);
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
    mx.resize(n);
    mn.resize(n);

    int st = 0;
    while(g[st].size() == 0 || seen[st]){
        ++st;
        dfs(st, 0, 1001001001);
    }

    ll gmx = 0;
    ll gmn = 1001001001;
    rep(i, n){
        gmx = max(gmx, mx[i]);
        gmn = min(gmn, mn[i]);
    }

    cout << gmx - gmn << endl;

    return 0;
}