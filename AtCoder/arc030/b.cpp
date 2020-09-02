#include <iostream>
#include <vector>
using namespace std;

int x;
vector<int> h;
vector<vector<int>> g;

int dfs(int v, vector<bool> seen){
    seen[v] = true;
    if(v!=x && g[v].size()==1){
        if(h[v] == 1) return 2;
        else return -1;
    }
    
    int ret = 0;

    for(int nv: g[v]){
        if(seen[nv]) continue;
        int d = dfs(nv, seen);
        if(d > 0) ret += d;
    }

    if(v == x) return ret;
    if(ret > 0) return ret+2;
    else if(ret==0 && h[v]==1) return 2;
    else return 0;
}


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n >> x;
    --x;

    h.resize(n);
    for(int i = 0; i < n; ++i) cin >> h[i];
    
    g.resize(n);
    for(int i = 0; i < n-1; ++i){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    vector<bool> seen(n, false);
    int res = dfs(x, seen);
    
    cout << res << endl;

    return 0;
}
