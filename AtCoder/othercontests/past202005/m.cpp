#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int k;
vector<vector<int>> dist;
vector<vector<int>> dp;

int rec(int s, int v){
    if(dp[s][v] != -1) return dp[s][v];
    if(s == (1<<k)-1) return dp[s][v] = 0;

    int ret = 1001001001;
    rep(nv, k){
        if(!(s & (1<<nv))){
            ret = min(ret, rec(s|(1<<nv), nv) + dist[v][nv]);
        }
    }
    return dp[s][v] = ret;
}

int main() {
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

    int s;
    cin >> s >> k;
    --s;
    vector<int> t(k);
    rep(i, k) {
        cin >> t[i];
        --t[i];
    }

    dist.assign(k+1, vector<int>(k+1, -1));

    rep(i, k+1){
        int sv;
        if(i < k) sv = t[i];
        else sv = s;

        queue<int> q;
        q.push(sv);
        vector<int> d(n, -1);
        d[sv] = 0;
        while(!q.empty()){
            int v = q.front();
            q.pop();

            for(int nv: g[v]){
                if(d[nv] != -1) continue;

                d[nv] = d[v] + 1;
                q.push(nv);
            }

            bool flg = true;
            rep(j, k+1){
                if(i == j) continue;
                int gv;
                if(j < k) gv = t[j];
                else gv = s;

                if(d[gv] == -1){
                    flg = false;
                    break;
                }
            }

            if(flg) break;
        }

        vector<int> di(k+1);
        rep(j, k+1){
            if(i == j) di[j] = 0;
            else{
                int gv;
                if(j < k) gv = t[j];
                else gv = s;

                di[j] = d[gv];
            }
        }

        dist[i] = di;

    }

    // rep(i, k+1){
    //     rep(j, k+1) cout << dist[i][j] << " ";
    //     cout << endl;
    // }

    dp.assign(1<<k, vector<int>(k+1, -1));

    int res = rec(0, k);

    cout << res << endl;


    return 0;
}