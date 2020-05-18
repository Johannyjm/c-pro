#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
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
    queue<int> q;
    q.push(0);

    map<int, int> nxt;

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(int nv: g[v]){
            if(dist[nv] != INF) continue;

            dist[nv] = dist[v] + 1;
            nxt[nv] = v;
            q.push(nv);
        }
    }


    bool flg = false;
    rep(i, n){
        if(dist[i] == INF) flg = true;
    }

    if(flg) cout << "No" << endl;
    else{
        cout << "Yes" << endl;
        rep1(i, n){
            if(dist[i] == 1) cout << 1 << endl;
            else cout << nxt[i]+1 << endl;
        }
    }

    return 0;
}