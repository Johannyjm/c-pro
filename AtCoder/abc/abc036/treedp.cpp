#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;
vector<vector<int>> g;
int rec(int v, int prev){
    if(dp[v] > 0) return dp[v];

    
    int ret = 0;
    for(int nv: g[v]){
        if(nv == prev) continue;
        
        ret = max(ret, rec(nv, v));
    }

    return dp[v] = ret+1;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    g.resize(n);
    
    for(int i = 0; i < n-1; ++i){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int r = 0;
    cin >> r;
    --r;
    
    dp.resize(n, 0);
    cout << rec(r, -1) << endl;

    return 0;
}
