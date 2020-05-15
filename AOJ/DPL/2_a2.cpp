#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int n;
vector<vector<int>> d(16, vector<int>(16));
vector<vector<int>> dp(1<<16, vector<int>(16));

int solve(int s, int v){
    if(dp[s][v] >= 0) return dp[s][v];
    if(s==(1<<n)-1 && v==0) return dp[s][v] = 0;

    int tmp = 1001001001;
    rep(u, n){
        if(!(s>>u & 1)) tmp = min(tmp, solve(s|1<<u, u) + d[v][u]);
    }
    return dp[s][v] = tmp;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int m;
    cin >> n >> m;
    const int INF = 1001001001;
    rep(i, n) rep(j, n) d[i][j] = INF;
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = c;
    }
    
    dp.assign(1<<16, vector<int>(16, -1));
    int res = solve(0, 0);

    if(res == INF) cout << -1 << endl;
    else cout << res << endl;

    return 0;
}