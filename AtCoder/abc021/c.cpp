#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n, a, b, m;
    cin >> n >> a >> b >> m;
    --a;
    --b;
    
    vector<vector<int>> g(n);
    for(int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        --x;
        --y;

        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    queue<int> q;
    q.push(a);
    const int INF = 1001001001;
    vector<int> dist(n, INF);
    dist[a] = 0;

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int nv: g[v]){
            if(dist[nv] != INF) continue;

            dist[nv] = dist[v] + 1;
            q.push(nv);
        }
    }

    int res = 1;
    q.push(b);
    vector<bool> seen(n, false);
    seen[b] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(v == a) break;

        int cnt = 0;
        for(int nv: g[v]){
            cout << v << " " << nv << " " << dist[v] << " " << dist[nv] << endl;
            if(dist[nv] != dist[v] - 1) continue;
            if(seen[nv]) continue;


            ++cnt;
            q.push(nv);
            seen[nv] = true;
        }
        cout << cnt << endl;
        cout << endl;

        res *= cnt;
    }

    cout << res << endl;

    return 0;
}
