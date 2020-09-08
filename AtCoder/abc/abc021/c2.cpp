#include <iostream>
#include <vector>
#include <queue>
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


    q.push(b);
    int res = 1;
    vector<bool> seen(n, false);
    const int mod = 1000000007;
    
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(v == a) break;
        if(seen[v]) continue;

        int cnt = 0;
        for(int nv: g[v]){
            if(seen[nv]) continue;
            if(dist[nv] != dist[v] - 1) continue;
            
            ++cnt;
            q.push(nv);
        }

        if(!seen[v]) res = (res * cnt) % mod;
        seen[v] = true;
    }

    cout << res << endl;

    return 0;
}
