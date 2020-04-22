#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

vector<vector<int>> g;
vector<bool> seen;
vector<int> cnt;
vector<int> res;

void dfs(int v, int pv){
    seen[v] = true;
    res[v] = res[pv] + cnt[v];

    for(int nv: g[v]){
        if(seen[nv]) continue;
        dfs(nv, v);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n>> q;

    g.resize(n);
    rep(i, n-1){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        if(a) g[b].push_back(a);
    }

    cnt.resize(n, 0);
    rep(i, q){
        int p, x;
        cin >> p >> x;
        --p;
        cnt[p] += x;
    }

    res.resize(n, 0);
    seen.resize(n, false);
    res[0] = cnt[0];
    for(int nv: g[0]){
        dfs(nv, 0);
    }

    rep(i, n) cout << res[i] << " ";
    cout << endl;

    return 0;
}