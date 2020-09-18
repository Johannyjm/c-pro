#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

struct Edge{
    int to;
    int year;

    Edge(int t, int y): to(t), year(y) {}
};

vector<vector<Edge>> g;
map<int, map<int, int>> dp;
int rec(int v, int w, vector<bool> seen){
    if(dp[v][w] > 0) return dp[v][w];
    seen[v] = true;

    int ret = 1;
    for(auto ne: g[v]){
        if(ne.year <= w) continue;
        if(seen[ne.to]) continue;

        ret += rec(ne.to, w, seen);
    }

    return dp[v][w] = ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    g.resize(n);
    for(int i = 0; i < m; ++i){
        int a, b, y;
        cin >> a >> b >> y;
        --a;
        --b;

        g[a].push_back(Edge(b, y));
        g[b].push_back(Edge(a, y));
    }
    
    int q;
    cin >> q;
    vector<bool> seen;
    for(int i = 0; i < q; ++i){
        int v, w;
        cin >> v >> w;
        --v;

        seen.assign(n, false);
        seen[v] = true;
        cout << rec(v, w, seen) << "\n";
    }

    return 0;
}

