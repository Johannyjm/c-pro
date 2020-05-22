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

    int n, m, st;
    cin >> n >> m >> st;

    Graph g(n);
    rep(_, m){
        int a, b, c;
        cin >> a >> b >> c;

        g[a].push_back(Edge(b, c));
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, st));
    const int INF = 1001001001;
    vector<int> dist(n, INF);
    dist[st] = 0;

    while(!pq.empty()){
        pair<int, int> p = pq.top();
        pq.pop();
        int v = p.second;

        for(auto ne: g[v]){
            if(dist[v] + ne.weight < dist[ne.to]){
                dist[ne.to] = dist[v] + ne.weight;
                pq.push(make_pair(dist[ne.to], ne.to));
            }
        }
    }

    rep(i, n) {
        if(dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }

    return 0;
}