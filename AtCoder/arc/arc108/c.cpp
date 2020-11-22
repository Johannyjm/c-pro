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

    Edge(int t, int c): to(t), color(c) {}
};

int main(){
    // cin.tie(nullptr);
    // ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    dsu uf(n);
    vector<vector<Edge>> g(n);
    vector<unordered_set<int>> cols(n);

    rep(i, m){
        int u, v, c;
        cin >> u >> v >> c;

        --u;
        --v;

        if(uf.same(u, v)) continue;
        g[u].push_back(Edge(v, c));
        g[v].push_back(Edge(u, c));
        
        uf.merge(u, v);        
        cols[u].insert(c);
        cols[v].insert(c);
    }

    vector<int> res(n, -1);

    queue<int> q;
    q.push(0);
    vector<bool> fixed(n, false);

    while(!q.empty()){
        int v = q.front();
        q.pop();

        if(res[v] == -1){
            int col = 1;
            while(cols[v].count(col) != 0) ++col;
            res[v] = col;
            fixed[v] = true;

            for(auto ne: g[v]){
                int nv = ne.to;
                if(fixed[nv]) continue;
                if(res[nv] != res[v]){
                    res[nv] = ne.color;
                    fixed[nv] = true;
                }

                q.push(nv);
            }
        }

        else{
            for(auto ne: g[v]){
                int nv = ne.to;
                if(fixed[nv]) continue;
                if(ne.color != res[v]){
                    res[nv] = ne.color;
                    fixed[nv] = true;
                }
                q.push(nv);
            }
        }
    }

    for(auto e: res) cout << e << "\n";

    return 0;
}