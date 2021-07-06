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
int n, m;
vector<vector<Edge>> g;

vector<ll> dijkstra(int st){
    
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    g.resize(n);
    rep(i, m){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        --a;
        --b;
        g[a].push_back(Edge(b, c));
        g[b].push_back(Edge(a, c));
    }

    const int INF = 1001001001;
    vector<vector<int>> minv(n, vector<int>(n, INF));
    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    rep(st, n){
        dist[st] = dijkstra(st);
    }

    

    return 0;
}