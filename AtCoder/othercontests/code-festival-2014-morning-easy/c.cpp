#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

struct Edge{
    int to;
    int weight;

    Edge(int t, int w): to(t), weight(w) {}
};

const int INF = 1001001001;
vector<vector<Edge>> g;
int n;

vector<int> dijkstra(int st){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, st});

    vector<int> dist(n, INF);
    dist[st] = 0;

    while(!pq.empty()){
        auto [d, v] = pq.top();
        pq.pop();

        if(dist[v] != d) continue;

        for(auto ne: g[v]){
            int nv = ne.to;

            if(dist[nv] > dist[v] + ne.weight){
                dist[nv] = dist[v] + ne.weight;

                pq.push({dist[nv], nv});
            }
        }
    }

    return dist;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int m, s, t;
    cin >> n >> m >> s >> t;

    --s;
    --t;

    g.resize(n);
    rep(i, m){
        int x, y, d;
        cin >> x >> y >> d;

        --x;
        --y;
        g[x].push_back(Edge(y, d));
        g[y].push_back(Edge(x, d));
    }

    vector<int> d_from_s = dijkstra(s);
    vector<int> d_from_t = dijkstra(t);

    rep(i, n){
        if(d_from_s[i] == d_from_t[i] && d_from_s[i] != INF){
            cout << i+1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}