#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

const int INF = 1001001001;
int k;
// vector<vector<int>> dp;
int dp[1<<18][18];
vector<vector<int>> dist;
int rec(int s, int v){
    if(dp[s][v] >= 0) return dp[s][v];
    if(s == (1<<k) - 1) return dp[s][v] = 0;

    int ret = INF;
    rep(nv, k){
        if(s & (1<<nv)) continue;
        ret = min(ret, rec(s|(1<<nv), nv) + dist[v][nv]);
    }

    return dp[s][v] = ret;
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
    
    cin >> k;
    // dp.resize(1<<k, vector<int>(k));
    vector<int> c(k);
    rep(i, k){
        cin >> c[i];
        --c[i];
    }

    dist.resize(k, vector<int>(k, INF));
    queue<int> q;
    rep(i, k){
        int st = c[i];
        vector<int> d(n, INF);
        d[st] = 0;
        q.push(st);
        while(!q.empty()){
            int v = q.front();
            q.pop();

            for(auto nv: g[v]){
                if(d[nv] != INF) continue;

                d[nv] = d[v] + 1;
                q.push(nv);
            }
        }

        rep(j, k){
            if(d[c[j]] == INF){
                cout << -1 << endl;
                return 0;
            }
            dist[i][j] = d[c[j]];
        }
    }

    // rep(i, k){
    //     rep(j, k) cout << dist[i][j] << " ";
    //     cout << endl;
    // }

    int res = INF;
    rep(i, k){
        // dp.assign(1<<k, vector<int>(k, -1));
        rep(j, 1<<k){
            rep(l, k) dp[j][l] = -1;
        }
        res = min(res, rec(0, i));
    }

    cout << res+1 << endl;

    return 0;
}