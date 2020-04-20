#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

vector<vector<int>> g;
vector<bool> seen;
vector<int> found;

void dfs(int v){
    seen[v] = true;
    found.push_back(v);

    if(g[v].size()==0){
        return;
    }

    for(int nv: g[v]){
        if(!seen[nv]){
            dfs(nv);
            found.push_back(nv);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    g.resize(n);
    seen.resize(n, false);

    rep(i, n){
        int u, k;
        cin >> u >> k;
        --u;
        rep(j, k){
            int v;
            cin >> v;
            --v;

            g[u].push_back(v);
        }
    }

    rep(i, n){
        if(!seen[i]) {
            dfs(i);
            found.push_back(i);
        }
    }
    
    vector<vector<int>> res(n, vector<int>(2, -1));
    rep(i, n){
        rep(j, found.size()){
            if(found[j]==i && res[i][0]==-1) res[i][0] = j+1;
            if(found[j]==i && res[i][0]!=-1) res[i][1] = j+1;
        }
    }

    rep(i, n) cout << i+1 << " " << res[i][0] << " " << res[i][1] << endl;

    return 0;
}