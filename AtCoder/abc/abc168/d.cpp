#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    queue<int> q;
    q.push(0);
    const int INF = 1001001001;
    vector<int> dist(n, INF);
    dist[0] = 0;

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(auto nv: g[v]){
            if(dist[nv] != INF) continue;
            dist[nv] = dist[v] + 1;
            q.push(nv);
        }
    }

    cout << "Yes" << endl;
    rep1(v, n){
        for(auto nv: g[v]){
            if(dist[nv] == dist[v] - 1){
                cout << nv+1 << endl;
                break;
            }
        }
    }


    return 0;
}