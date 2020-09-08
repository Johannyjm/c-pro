#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1ll << 60;

int n;
vector<vector<ll>> dist;
vector<vector<ll>> dp;

ll solve(int s, int v){
    if(dp[s][v] >= 0) return dp[s][v];
    if(s==(1<<n)-1 && v==0) return dp[s][v] = 0;

    ll ret = INF;
    rep(nv, n){
        if(!(s & (1<<nv))) ret = min(ret, solve(s|(1<<nv), nv) + dist[v][nv]);
    }

    dp[s][v] = ret;
    return ret;
}


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int m;
    cin >> n >> m;

    dist.assign(n, vector<ll>(n, INF));
    rep(i, m){
        int s, t;
        ll d;
        cin >> s >> t >> d;

        dist[s][t] = d;
    }

    dp.assign(1<<n, vector<ll>(n, -1));
    ll res = solve(0, 0);

    if(res == INF) cout << -1 << endl;
    else cout << res << endl;

    return 0;
}