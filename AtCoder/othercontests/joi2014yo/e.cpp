#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

struct Edge{
    int to, weight;
    Edge(int t, int w): to(t), weight(w) {}
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> c(n), r(n);
    rep(i, n) cin >> c[i] >> r[i];

    vector<vector<int>> g(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<vector<Edge>> g2(n);
    rep(st, n){
        queue<int> q;
        q.push(st);
        
        vector<int> dist(n, INF);
        dist[st] = 0;
        while(!q.empty()){
            int v = q.front();
            q.pop();

            if(dist[v] >= r[st]) break;

            for(auto nv: g[v]){
                if(dist[nv] != INF) continue;

                dist[nv] = dist[v] + 1;
                q.push(nv);
            }
        }

        rep(v, n){
            if(dist[v] == INF) continue;
            if(v == st) continue;
            g2[st].push_back(Edge(v, c[st]));
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    vector<int> dist2(n, INF);
    dist2[0] = 0;

    while(!pq.empty()){
        auto [d, v] = pq.top();
        pq.pop();

        if(dist2[v] != d) continue;

        for(auto ne: g2[v]){
            int nv = ne.to;
            if(dist2[nv] > dist2[v] + ne.weight){
                dist2[nv] = dist2[v] + ne.weight;
                pq.push({dist2[nv], nv});
            }
        }
    }


    cout << dist2[n-1] << endl;

    return 0;
}