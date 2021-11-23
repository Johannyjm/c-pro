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
    vector<int> h(n, 0);
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        
        g[a].push_back(b);
        ++h[b];
    }
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; ++i){
        if(h[i] == 0) pq.push(i);
    }

    vector<int> res;

    while(!pq.empty()){
        int v = pq.top();
        pq.pop();
        
        res.push_back(v + 1);

        for(auto nv: g[v]){
            --h[nv];

            if(h[nv] == 0) pq.push(nv);
        }
    }

    if(res.size() != n){
        cout << -1 << endl;
        return 0;
    }

    for(auto e: res) cout << e << " ";
    cout << endl;

    return 0;
}
