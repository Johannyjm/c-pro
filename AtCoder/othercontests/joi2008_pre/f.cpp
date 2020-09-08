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

    int n, k;
    cin >> n >> k;

    Graph g(n);
    const int INF = 1001001001;

    rep(_, k){
        int cmd;
        cin >> cmd;

        if(cmd == 1){
            int c, d, e;
            cin >> c >> d >> e;
            --c;
            --d;
            
            g[c].push_back(Edge(d, e));
            g[d].push_back(Edge(c, e));
        }

        else{
            int a, b;
            cin >> a >> b;
            --a;
            --b;

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push(make_pair(0, a));
            
            vector<int> dist(n, INF);
            dist[a] = 0;

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

            if(dist[b] == INF) cout << -1 << endl;
            else cout << dist[b] << endl;

        }
    }

    return 0;
}