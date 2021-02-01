#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int k, C;
vector<int> c;
vector<vector<int>> dist;
vector<vector<int>> kdist;
vector<vector<int>> dp;
const int INF = 1001001001;

int rec(int s, int v){
    if(dp[s][v] >= 0) return dp[s][v];
    if(s==(1<<k)-1) return dp[s][v] = 0;

    int ret = INF;
    rep(nv, k){
        if(s & (1<<nv)) continue;
        ret = min(ret, rec(s|(1<<nv), nv) + kdist[v][nv]);
    }

    dp[s][v] = ret;
    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    // int k;
    cin >> k;
    c.resize(k);
    rep(i, k){
        cin >> c[i];
        --c[i];
    }

    dist.resize(k, vector<int>(n, INF));
    queue<int> q;
    rep(i, k){
        dist[i][c[i]] = 0;
        q.push(c[i]);

        while(!q.empty()){
            int v = q.front();
            q.pop();

            for(auto nv: g[v]){
                if(dist[i][nv] != INF) continue;

                dist[i][nv] = dist[i][v] + 1;
                q.push(nv);
            }
        }
    }

    // rep(i, k){
    //     rep(j, n) cout << dist[i][j] << " ";
    //     cout << endl;
    // }

    kdist.resize(k, vector<int>(k, INF));
    rep(i, k){
        rep(j, k) kdist[i][j] = dist[i][c[j]];
    }

    // rep(i, k){
    //     rep(j, k) cout << kdist[i][j] << " ";
    //     cout << endl;
    // }



    int res = INF;
    dp.resize(1<<k, vector<int>(k, -1));
    rep(i, k){
        // vector<bool> seen(k, false);
        // seen[i] = true;
        // C = c[i];
        dp.assign(1<<k, vector<int>(k, -1));
        int cost = rec(0, i);
        res = min(res, cost);

        // cout << cost << endl;
        // rep(i, 1<<k){
        //     rep(j, k) cout << dp[i][j] << " ";
        //     cout << endl;
        // }
        // cout << endl;
    }

    if(res == INF) cout << -1 << endl;
    else cout << res+1 << endl;

    return 0;
}