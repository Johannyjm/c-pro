#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

struct Edge{
    int to;
    ll weight;

    Edge(int t, ll w): to(t), weight(w){}
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<vector<Edge>> g(n);
    rep(i, n-1){
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u;
        --v;

        g[u].push_back(Edge(v, w));
        g[v].push_back(Edge(u, w));
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 0});
    const ll LINF = 1ll<<60;
    vector<ll> dist(n, LINF);
    dist[0] = 0;
    while(!pq.empty()){
        pair<ll, int> p = pq.top();
        pq.pop();

        int v = p.second;
        for(auto ne: g[v]){
            if(dist[v]+ne.weight < dist[ne.to]){
                dist[ne.to] = dist[v] + ne.weight;

                pq.push({dist[ne.to], ne.to});
            }
        }
    }

    // for(auto e: dist) cout << e << " ";
    // cout << endl;

    // queue<int> q;
    // q.push(0);
    // const int INF = 1001001001;
    // vector<int> steps(n, INF);
    // steps[0] = 0;
    // while(!q.empty()){
    //     int v = q.front();
    //     q.pop();

    //     for(auto ne: g[v]){
    //         if(steps[ne.to] != INF) continue;

    //         steps[ne.to] = steps[v] + 1;
    //         q.push(ne.to);
    //     }
    // }

    // for(auto e: steps) cout << e << " ";
    // cout << endl;
    
    for(auto e: dist){
        if(e%2==0) cout << 0 << endl;
        else cout << 1 << endl;
    }

    return 0;
}