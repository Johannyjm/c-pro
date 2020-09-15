#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;
 
struct Edge{
    int to;
    ll weight;

    Edge(int t, ll w): to(t), weight(w) {}
};

int n;
const ll INF = 1ll << 60;
 
vector<ll> dijkstra(vector<vector<Edge>> g){
    vector<ll> dist(n, INF);
    dist[0] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 0});
 
    while(!pq.empty()){
        int v = pq.top().second;
        pq.pop();
 
        for(auto next: g[v]){
            if(dist[next.to] > dist[v] + next.weight){
                dist[next.to] = dist[v] + next.weight;
                pq.push({dist[next.to], next.to});
            }
        }
    }
 
    return dist;
}
 
 
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
 
    ll m, t;
    cin >> n >> m >> t;
 
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
 
    vector<vector<Edge>> g(n);
    vector<vector<Edge>> gr(n);
    for(int i = 0; i < m; ++i){
        ll a, b, c;
        cin >> a >> b >> c;
        --a;
        --b;
        g[a].push_back(Edge(b, c));
        gr[b].push_back(Edge(a, c));
    }
 
    vector<ll> dist = dijkstra(g);
    vector<ll> distr = dijkstra(gr);
    
    ll res = 0;
    for(int i = 0; i < n; ++i){
        ll overhead = dist[i] + distr[i];
        ll cand = max(0ll, t-overhead) * a[i];
        res = max(res, cand);
    }
 
    cout << res << endl;
 
 
    return 0;
}
