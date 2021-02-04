#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

vector<vector<int>> g;
int dfs(int v){
    if(int(g[v].size()) == 0) return 1;
    if(int(g[v].size()) == 1) return 2*dfs(g[v][0])+1;
    
    int mx = 0;
    int mn = 1001001001;
    for(auto nv: g[v]){
        int val = dfs(nv);
        mx = max(mx, val);
        mn = min(mn, val);
    }

    return mx + mn + 1;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> b(n, -1);
    rep1(i, n) cin >> b[i];
    g.resize(n);
    rep1(i, n){
        g[b[i]-1].push_back(i);
    }

    cout << dfs(0) << endl;

    return 0;
}