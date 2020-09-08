#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

struct Edge{
    int to;
    int weight;
    Edge(int t, int w): to(t), weight(w) {}
};

using Graph = vector<vector<Edge>>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int v, e, r;
    cin >> v >> e >> r;

    Graph g(v);
    rep(i, e){
        int s, t, d;
        cin >> s >> t >> d;
        g[s].push_back(Edge(t, d));
    }

    const int INF = 1001001001;
    vector<int> dist(v, INF);
    dist[r] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, r));

    while(!pq.empty()){
        pair<int, int> p = pq.top();
        int cv = pq.top().second;
        pq.pop();

        for(auto nv: g[cv]){
            if(dist[cv] + nv.weight < dist[nv.to]){
                dist[nv.to] = dist[cv] + nv.weight;
                pq.push(make_pair(dist[nv.to], nv.to));
            }
        }
    }

    rep(i, v){
        if(dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }

    return 0;
}