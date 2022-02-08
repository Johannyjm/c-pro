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

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<vector<Edge>> g(n);
    for(int i = 0; i < n-1; ++i){
        int a, b;
        ll c;
        cin >> a >> b >> c;

        --a;
        --b;
        g[a].push_back(Edge(b, c));
        g[b].push_back(Edge(a, c));
    }

    queue<int> q;
    q.push(0);

    const ll INF = 1ll << 60;
    vector<ll> dist(n, INF);
    dist[0] = 0;

    while(!q.empty()){
        int v = q.front();
        q.pop();
        
        for(auto ne: g[v]){
            int nv = ne.to;
            if(dist[nv] != INF) continue;

            dist[nv] = dist[v] + ne.weight;
            q.push(nv);
        }
    }

    for(int i = 0; i < n; ++i){
        cout << dist[i] % 2 << endl;
    }
    
    return 0;
}
