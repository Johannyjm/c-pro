#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
using Graph = vector<vector<int>>;

vector<bool> seen;
void dfs(const Graph &G, int v){
    seen[v] = true;

    for(auto next_v: G[v]){
        if(seen[next_v]) continue;
        dfs(G, next_v);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    Graph G(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    seen.assign(n, false);
    dfs(G, 0);

    return 0;
}