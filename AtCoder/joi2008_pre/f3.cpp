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

    const int INF = 1001001001;
    vector<vector<int>> dist(n, vector<int>(n, INF));
    rep(i, n) dist[i][i] = 0;

    rep(_, m){
        int cmd;
        cin >> cmd;

        if(cmd == 0){
            int a, b;
            cin >> a >> b;
            --a;
            --b;

            if(dist[a][b] == INF) cout << -1 << endl;
            else cout << dist[a][b] << endl;
        }

        else{
            int c, d, e;
            cin >> c >> d >> e;
            --c;
            --d;

            dist[c][d] = min(dist[c][d], e);
            dist[d][c] = min(dist[d][c], e);

            rep(k, n) rep(i, n) rep(j, n){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    return 0;
}