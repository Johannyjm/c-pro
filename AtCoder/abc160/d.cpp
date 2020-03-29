#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

using Graph = vector<vector<int>>;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, x, y;
    cin >> n >> x >> y;
    --x;
    --y;

    Graph G(n);

    rep1(i, n){
        G[i-1].push_back(i);
        G[i].push_back(i-1);
    }

    G[x].push_back(y);
    G[y].push_back(x);

    vector<vector<int>> dist(n, vector<int>(n, -1));
    vector<int> res(n+10);
    rep(i, n){
        dist[i][i] = 0;

        queue<int> q;
        q.push(i);

        while(!q.empty()){
            int v = q.front();
            q.pop();

            for (int nv : G[v]) {
                if (dist[i][nv] != -1) continue;
                
                dist[i][nv] = dist[i][v] + 1;
                ++res[dist[i][nv]];
                q.push(nv);
            }

        }
    }

    // rep(i, n){
    //     rep(j, n) cout << dist[i][j];
    //     cout << endl;
    // }

    rep1(i, n){
        cout << res[i]/2 << endl;
    }



    return 0;
}