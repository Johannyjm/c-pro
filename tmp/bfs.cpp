


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int st = 0;
    int go = n-1;

    const int INF = 1001001001;
    vector<int> dist(n, INF);
    dist[st] = 0;
    
    queue<int> q;
    q.push(st);

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int nv: g[v]){
            if(dist[nv] != INF) continue;
            
            dist[nv] = dist[v] + 1;
            q.push(nv);
        }
    }

    for(auto e: dist){
        cout << e << " ";
    }
    cout << endl;

}
