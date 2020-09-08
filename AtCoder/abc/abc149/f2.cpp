#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

const int N = 220000;
const int P = 1000000007;

vector<int> g[N];
int sz[N], p2[N], n, res, inv2 = (P + 1) / 2;

int dfs(int u, int p){
    sz[u] = 1;
    for(int v : g[u]){
        if (v != p) sz[u] += dfs(v, u);
    }
    if(p != 0)
        res = (res + (ll)(1 + P - p2[sz[u]]) * (1 + P - p2[n - sz[u]]) % P) % P;
    return sz[u];
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    p2[0] = 1;
    for (int i = 1; i < N; ++i) p2[i] = (ll) p2[i - 1] * inv2 % P;
    
    cin >> n;
    res = (P - (int64_t)n * inv2 % P) % P;
    for (int i = 1, v, u; i < n; ++i){
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    
    dfs(1, 0);
    
    cout << (ll)(res + (ll)(1 + P - p2[n]) % P) % P << endl;

    return 0;
}