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

    int n, m, r;
    cin >> n >> m >> r;

    Graph g(n);
    rep(i, m){
        int s, t, d;
        cin >> s >> t >> d;

        g[s].push_back(Edge(t, d));
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, r));
    const int INF = 1001001001;
    vector<int> cost(n, INF);
    cost[r] = 0;

    while(!pq.empty()){
        pair<int, int> p = pq.top();
        int v = p.second;
        pq.pop();

        for(auto edge: g[v]){
            if(cost[v] + edge.weight < cost[edge.to]){
                cost[edge.to] = cost[v] + edge.weight;
                pq.push(make_pair(cost[edge.to], edge.to));
            }
        }
    }

    rep(i, n){
        if(cost[i] != INF) cout << cost[i] << endl;
        else cout << "INF" << endl;
    }

    return 0;
}