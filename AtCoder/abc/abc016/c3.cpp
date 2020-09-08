#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    rep(_, m){
        int a, b;
        cin >> a >> b;
        --a;
        --b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    rep(i, n){
        queue<int> q;
        q.push(i);
        const int INF = 1001001001;
        vector<int> dist(n, INF);
        dist[i] = 0;

        while(!q.empty()){
            int v = q.front();
            q.pop();

            for(auto nv: g[v]){
                if(dist[nv] != INF) continue;

                dist[nv] = dist[v] + 1;
                q.push(nv);
            }
        }

        int res = 0;
        rep(i, n){
            if(dist[i] == 2) ++res;
        }

        cout << res << endl;
    }

    return 0;
}