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

    const int INF = 1001001001;
    vector<int> dist(n, INF);
    dist[0] = 0;
    vector<int> cnt(n, 0);
    cnt[0] = 1;

    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(auto nv: g[v]){
            if(dist[nv] != INF) continue;

            dist[nv] = dist[v] + 1;
            // cnt[nv] = (cnt[nv] + cnt[v]) % 1000000007;
            q.push({nv});
        }
    }

    q.push(0);
    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(auto nv: g[v]){
            if(dist[nv] != dist[v] + 1) continue;
            if(cnt[nv] == 0) q.push(nv);

            cnt[nv] = (cnt[nv] + cnt[v]) % 1000000007;
        }
    }

    // for(auto e: dist) cout << e << " ";
    // cout << endl;
    // for(auto e: cnt) cout << e << " ";
    // cout << endl;

    cout << cnt[n-1] << endl;
    

    return 0;
}