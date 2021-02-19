#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> g;
vector<int> dp;
int dfs(int v){
    if(dp[v] >= 0) return dp[v];
    if(g[v].size() == 0) return dp[v] = 0;

    int ret = 0;
    for(auto nv: g[v]){
        ret = max(ret, dfs(nv) + 1);
    }

    return dp[v] = ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    g.resize(n);
    dp.resize(n, -1);
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
    }

    int res = 0;
    for(int st = 0; st < n; ++st){
        res = max(res, dfs(st));
    }

    cout << res << endl;
    
}
