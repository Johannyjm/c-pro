#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> g(n);
    const int INF = 1001001001;
    vector<vector<int>> cost(n, vector<int>(n, INF));
    for(int i = 0; i < k; ++i){
        int cmd;
        cin >> cmd;

        if(cmd == 1){
            int from, to, c;
            cin >> from >> to >> c;
            --from;
            --to;
            
            g[from].push_back(to);
            g[to].push_back(from);
            cost[from][to] = min(cost[from][to], c);
            cost[to][from] = min(cost[to][from], c);
        }
        else{
            int from, to;
            cin >> from >> to;
            --from;
            --to;
            
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push(make_pair(0, from));
            vector<int> dist(n, INF);
            dist[from] = 0;

            while(!pq.empty()){
                pair<int, int> p = pq.top();
                pq.pop();
                
                int v = p.second;
                for(int nv: g[v]){
                    if(dist[v] + cost[v][nv] < dist[nv]){
                        dist[nv] = dist[v] + cost[v][nv];
                        pq.push(make_pair(dist[nv], nv));
                    }
                }
            }

            if(dist[to] == INF) cout << -1 << endl;
            else cout << dist[to] << endl;
        }
    }
    
}
