#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n;
vector<int> c, cnt;
vector<vector<int>> g;
vector<bool> isntgood, seen;

void dfs(int v){
    seen[v] = true;
    ++cnt[c[v]];

    for(auto nv: g[v]){
        if(seen[nv]) continue;
        if(cnt[c[nv]] > 0) isntgood[nv] = true;

        dfs(nv, seen, cnt);
    }
} 

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    c.resize(n);
    for(int i = 0; i < n; ++i) cin >> c[i];
    g.resize(n);
    for(int i = 0; i < n-1; ++i){
        int a, b;
        cin >> a >> b;
        --a;
        --b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> cnt(110000, 0);
    vector<bool> seen(n, false);
    isntgood.resize(n, false);

    dfs(0, seen, cnt);

    for(int i = 0; i < n; ++i){
        if(!isntgood[i]) cout << i+1 << "\n";
    }

    return 0;
}
