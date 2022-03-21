#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

struct Edge{
    int to;
    ll weight;

    Edge(int t, ll w): to(t), weight(w) {}
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> g(n);
    const ll INF = 1ll << 60;
    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    vector<pair<int, int>> edges(m);
    rep(i, m){
        int a, b;
        ll c;
        cin >> a >> b >> c;

        --a;
        --b;
        g[a].push_back(Edge(b, c));
        g[b].push_back(Edge(a, c));
        dist[a][b] = c;
        dist[b][a] = c;

        edges[i] = {min(a, b), max(a, b)};
    }

    vector<vector<ll>> dp(n, vector<ll>(n, INF));
    rep(i, n){
        rep(j, n) dp[i][j] = dist[i][j];
        dp[i][i] = 0;
    }

    rep(k, n) rep(i, n) rep(j, n){
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    }

    // rep(i, n){
    //     rep(j, n) cout << dp[i][j] << " ";
    //     cout << endl;
    // }

    vector<vector<int>> use_cnt(n, vector<int>(n, 0));
    rep(st, n){
        vector<ll> cost(n, INF);
        cost[st] = 0;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        pq.push({0, st});

        vector<int> prev(n, -1);

        while(!pq.empty()){
            auto [d, v] = pq.top();
            pq.pop();

            if(cost[v] != d) continue;

            for(auto ne: g[v]){
                int nv = ne.to;

                if(cost[nv] > cost[v] + ne.weight){
                    cost[nv] = cost[v] + ne.weight;

                    pq.push({cost[nv], nv});
                    prev[nv] = v;
                }
            }
        }

        rep(go, n){
            if(go == st) continue;
            int cv = go;
            while(prev[cv] != st){
                int pv = prev[cv];
                use_cnt[min(pv, cv)][max(pv, cv)]++;
                cv = pv;
            }
        }

        // for(auto e: cost) cout << e << " ";
        // cout << endl;

    }

    int res = 0;
    rep(i, m){
        if(use_cnt[edges[i].first][edges[i].second] == 0) ++res;
    }
    cout << res << endl;

    return 0;
}