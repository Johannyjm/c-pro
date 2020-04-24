#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<vector<int>> g(n);
    rep(i, n){
        int u, k;
        cin >> u >> k;
        --u;

        rep(j, k){
            int v;
            cin >> v;
            --v;

            g[u].push_back(v);
        }
    }

    queue<int> q;
    vector<int> dist(n, -1);
    q.push(0);
    dist[0] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        
        for(int nv : g[v]){
            if(dist[nv] != -1) continue;

            dist[nv] = dist[v] + 1;
            q.push(nv);
        }
    }

    rep(i, n) cout << i+1 << " " << dist[i] << endl;

    return 0;
}