#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

vector<vector<int>> g;
vector<vector<ll>> ranks;
vector<bool> seen;
vector<ll> x;
void dfs(int v){

    seen[v] = true;
    vector<ll> ret;

    for(auto nv: g[v]){
        if(seen[nv]) continue;

        dfs(nv);
        for(auto e: ranks[nv]){
            ret.push_back(e);
        }
    }

    if(ret.size() == 0){
        ret.push_back(x[v]);
    }
    else{
        ret.push_back(x[v]);
        sort(ret.begin(), ret.end(), greater<ll>());
    }

    rep(i, min(20, (int)ret.size())){
        ranks[v].push_back(ret[i]);
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    x.resize(n);
    rep(i, n) cin >> x[i];

    g.resize(n);
    rep(i, n-1){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    ranks.resize(n);
    seen.resize(n, false);
    dfs(0);

    // cout << endl;
    // rep(i, n){
    //     for(auto e: ranks[i]) cout << e << " ";
    //     cout << endl;
    // }
    // cout << endl;

    rep(_, q){
        int v, k;
        cin >> v >> k;
        --v;
        --k;

        cout << ranks[v][k] << "\n";
    }
    


    return 0;
}