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

    const int INF = 2001001001;
    vector<vector<int>> dist(n, vector<int>(n, INF));
    rep(_, m){
        int s, t, d;
        cin >> s >> t >> d;

        dist[s][t] = d;
    }

    rep(i, n) dist[i][i] = 0;

    rep(k, n) rep(i, n) rep(j, n) {
        if(dist[i][k] == INF || dist[k][j] == INF) continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }

    rep(i, n) if(dist[i][i] != 0) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }

    rep(i, n){
        rep(j, n){
            if(dist[i][j] != INF) cout << dist[i][j];
            else cout << "INF";

            if(j != n-1) cout << " ";
        }
        cout << endl;
    }



    return 0;
}