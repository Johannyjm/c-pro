#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

struct Edge{
    int to;
    int weight;
    Edge(int t, int w): to(t), weight(w){}
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

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push(make_pair(0, r));
    const int INF = 1001001001;
    vector<int> cost(v, INF);
    cost[r] = 0;
    while(!q.empty()){
        pair<int, int> p = q.top();
        int cv = p.second;
        q.pop();

        // if(cost[cv] < p.first) continue;

        for(auto e: g[cv]){
            if(cost[e.to] > cost[cv] + e.weight){
                cost[e.to] = cost[cv] + e.weight;
                q.push(make_pair(cost[e.to], e.to));
            }
        }

    }

    rep(i, v){
        if(cost[i] != INF) cout << cost[i] << endl;
        else cout << "INF" << endl;
    }

    return 0;
}