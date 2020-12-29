#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    --s;
    --t;

    vector<vector<int>> g(n);
    const int INF = 1001001001;
    vector<vector<int>> cost(n, vector<int>(n, INF));
    rep(i, m){
        int x, y, d;
        cin >> x >> y >> d;
        --x;
        --y;

        g[x].push_back(y);
        g[y].push_back(x);
        cost[x][y] = d;
        cost[y][x] = d;
    }

    rep(start, n){
        if(start==s || start==t) continue;

        vector<int> dist(n, INF);
        dist[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});

        while(!pq.empty()){
            pair<int, int> p = pq.top();
            pq.pop();

            int v = p.second;
            for(auto nv: g[v]){
                if(dist[nv] > dist[v] + cost[v][nv]){
                    dist[nv] = dist[v] + cost[v][nv];
                    pq.push({dist[nv], nv});
                }
            }
        }

        // cout << "start: " << start << ", ";
        // for(auto e: dist) cout << e << " ";
        // cout << endl;

        if(dist[s]!=INF && dist[s] == dist[t]){
            cout << start+1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}