#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge{
    int to;
    int weight;

    Edge(int t, int w): to(t), weight(w){}
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, s;
    cin >> n >> m >> s;
    
    vector<vector<Edge>> g(n);
    for(int i = 0; i < m; ++i){
        int from, to, cost;
        cin >> from >> to >> cost;

        g[from].push_back(Edge(to, cost));
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, s));
    const int INF = 1001001001;
    vector<int> dist(n, INF);
    dist[s] = 0;
    
    while(!pq.empty()){
        pair<int, int> p = pq.top();
        pq.pop();
        int v = p.second;

        for(auto edge: g[v]){
            if(dist[edge.to] > dist[v] + edge.weight){
                dist[edge.to] = dist[v] + edge.weight;
                pq.push(make_pair(dist[edge.to], edge.to));
            }
        }
    }

//    for(int res: dist){
//        if(res == INF) cout << "INF" << endl;
//        else cout << res << endl;
//    }
    for(int i = 0; i < n; ++i){
        if(dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }

}
