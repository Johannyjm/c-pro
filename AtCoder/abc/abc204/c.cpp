#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

vector<vector<int>> g;
vector<bool> cango;
void dfs(int v){
    // cout << "dfs: " << v << endl;
    for(auto nv: g[v]){
        if(cango[nv]) continue;
        // cout << nv << endl;
        cango[nv] = true;
        dfs(nv);
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    
    g.resize(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
    }

    cango.resize(n, false);
    int res = 0;
    rep(st, n){
        cango.assign(n, false);
        cango[st] = true;

        dfs(st);

        // rep(i, n) cout << cango[i] << " ";
        // cout << endl;

        rep(i, n){
            // if(st == i) continue;
            if(cango[i]) ++res;
        }
    }

    cout << res << endl;

    return 0;
}