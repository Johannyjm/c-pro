#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; ++i){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(0);
    vector<bool> seen(n, false);
    seen[0] = true;
    vector<int> res;
    while(!pq.empty()){
        int v = pq.top();
        pq.pop();
        res.push_back(v);
        seen[v] = true;

        for(int nv: g[v]){
            if(seen[nv]) continue;
            pq.push(nv);
        }
    }

    for(int i = 0; i < n-1; ++i) cout << res[i]+1 << " ";
    cout << res.back()+1 << endl;

    return 0;
}
