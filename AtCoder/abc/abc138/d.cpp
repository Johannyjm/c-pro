#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int n, q;
vector<vector<int>> g;
vector<bool> seen;
vector<int> res;
void dfs(int v){
    seen[v] = true;

    for(int nv: g[v]){
        if(seen[nv]) continue;
        
        res[nv] += res[v];
        dfs(nv);
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> q;

    g.resize(n);
    rep(i, n-1){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    res.resize(n, 0);
    while(q--){
        int p, x;
        cin >> p >> x;
        --p;

        res[p] += x;
    }

    seen.resize(n, false);
    dfs(0);

    rep(i, n-1) cout << res[i] << " ";
    cout << res.back() << endl;

    return 0;
}