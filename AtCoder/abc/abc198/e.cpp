#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> c(n);
    for(int i = 0; i < n; ++i) cin >> c[i];
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; ++i){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    queue<int> q;
    q.push(0);
    vector<unordered_set<int>> seen(n);
    seen[0].insert(c[0]);
    vector<bool> isntgood(n, false);

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(auto nv: g[v]){
            if(seen[nv].size() != 0) continue;
            
            seen[nv] = seen[v];
            if(seen[nv].count(c[nv]) != 0) isntgood[nv] = true;
            else seen[nv].insert(c[nv]);

            q.push(nv);
        }
    }

    for(int i = 0; i < n; ++i){
        if(!isntgood[i]) cout << i + 1 << "\n";
    }

    return 0;
}
