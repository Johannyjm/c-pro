#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

const int INF = 1001001001;

int n, m, s, t;
vector<bool> seen;
vector<vector<int>> g;
vector<vector<ll>> cost;

vector<int> path_res;
int cost_res;

void dfs(int v, ll cost_now, vector<int> path_now){
    cout << v << " ";
    seen[v] = true;
    if(v == t){
        path_now.push_back(t);
        path_res = path_now;
        cost_res = cost_now;
        return;
    }

    for(auto nv: g[v]){
        if(seen[nv]) continue;
        if(cost[v][nv] == 0) continue;

        vector<int> tmp = path_now;
        tmp.push_back(nv);
        dfs(nv, min(cost_now, cost[n][nv]), tmp);
    }
}

void update(ll min_cost, vector<int> path){
    int l = path.size();
    rep(i, l-1){
        int from = path[i];
        int to = path[i+1];

        cost[from][to] -= min_cost;
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    s = 0;
    t = n-1;

    seen.resize(n);
    g.resize(n);
    cost.resize(n, vector<ll>(n, INF));
    rep(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        
        g[a].push_back(b);
        cost[a][b] = c;
    }

    ll res = 0;
    // ford-fulkerson algorithm
    while(1){
        
        seen.assign(n, false);

        vector<int> tmp;
        dfs(s, INF, tmp);

        cout << cost_res << endl;
        for(auto e: path_res) cout << e << " ";
        cout << endl;
        return 0;

        if(cost_res == 0) break;

        res += cost_res;

        update(cost_res, path_res);
    }

    cout << res << endl;

    return 0;
}