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
    ll weight;
    Edge(int t, ll w): to(t), weight(w) {}
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<Edge>> g(n);
    rep(i, n-1){
        ll u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;

        g[u].push_back(Edge(v, w));
        g[v].push_back(Edge(u, w));
    }

    fenwick_tree<ll> bit1(11000000), bit2(11000000);
    queue<int> q;
    q.push(0);
    vector<bool> seen(n, false);
    seen[0] = true;
    ll res = 0;
    
    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(auto ne: g[v]){
            int nv = ne.to;
            if(seen[nv]) continue;

            ll w = ne.weight;
            res += w;

            res += bit1.sum(0, w) * w;
            res += bit2.sum(w, 11000000);
            cout << nv+1 << " " << bit1.sum(0, w) * w << " " << bit2.sum(w, 11000000) << " " << res << endl;

            bit1.add(w, 1);
            bit2.add(w, w);

            seen[nv] = true;
            q.push(nv);
        }

    }

    cout << res << endl;
    return 0;
}