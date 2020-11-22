#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

struct Edge{
    int to;
    int color;

    Edge(int t, int c): to(t), color(c){}
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    
    vector<vector<Edge>> g(n);
    vector<unordered_set<int>> cst(n), ngst(n);

    dsu uf(n);
    
    rep(i, m){
        int u, v, c;
        
        cin >> u >> v >> c;
        --u;
        --v;

        if(uf.same(u, v)) continue;

        uf.merge(u, v);

        g[u].push_back(Edge(v, c));
        g[v].push_back(Edge(u, c));

        cst[u].insert(c);
        cst[v].insert(c);
    }

    vector<int> csts(n);
    rep(i, n){
        csts[i] = cst[i].size();
    }

    vector<int> res(n, -1);
    rep(i, n){
        if(csts[i] == 1){
            int col = g[i][0].color;
            res[i] = col;
            if(cst[g[i][0].to].count(col)) cst[g[i][0].to].erase(col);
            ngst[g[i][0].to].insert(col);
        }
    }

    int sv = 0;
    while(sv<n && res[sv] != -1) ++sv;
    if(sv == n){
        for(auto e: res) cout << e << "\n";
        return 0;
    }

    // queue<int> q;
    // q.push(sv);
    // while(!q.empty()){
    //     int v = q.front();
    //     q.pop();

    rep(v, n){
        if(res[v] != -1) continue;
        int col;
        if(cst[v].size() == 0){
            col = 1;
            while(ngst[v].count(col) != 0) ++col;
        }
        else col = *cst[v].begin();

        res[v] = col;
        
        for(auto ne: g[v]){
            if(res[ne.to] != -1) continue;
            if(cst[ne.to].count(col)) cst[ne.to].erase(col);
            ngst[ne.to].insert(col);
            // q.push(ne.to);
        }
    }

    rep(i, n){
        if(res[i] == -1){
            int col = 1;
            while(ngst[i].count(col) != 0) ++col;
            res[i] = col;
        }
    }


    for(auto e: res) cout << e << "\n";


    return 0;
}