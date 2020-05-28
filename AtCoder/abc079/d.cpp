#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    vector<vector<int>> c(10, vector<int>(10));
    rep(i, 10) rep(j, 10) cin >> c[i][j];
    
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];

    // const int INF = 1001001001;
    // vector<vector<int>> dist(10, vector<int>(10, INF));
    // rep(i, 10) dist[i][i] = 0;
    // rep(i, 10) rep(j, 10) dist[i][j] = a[i][j];
    
    rep(k, 10) rep(i, 10) rep(j, 10){
        c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
    }

    int res = 0;
    rep(i, h) rep(j, w){
        if(a[i][j] == -1) continue;
        res += c[a[i][j]][1];
    }

    cout << res << endl;

    return 0;
}