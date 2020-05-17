#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1ll << 60;
 
int n;
int res_c;
vector<vector<ll>> dist;
vector<vector<ll>> tle;
 
vector<vector<ll>> dp;
ll solve(int s, int v){
    if(dp[s][v] >= 0) {
        ++res_c;
        return dp[s][v];
    }

    if(s==(1<<n)-1 && v==0){
        return 0;
    }

    ll ret = INF;
    rep(nv, n){
        if(!(s & (1<<nv))){
            pair<ll, ll> np = solve(s|(1<<nv), nv)
            if(tle[v][nv] < v_cnt) continue;
            ret = min(ret, solve(s|(1<<nv), nv) + dist[v][nv]);
        }
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
    tle.assign(n, vector<ll>(n, INF));
    rep(i, m){
        int s, t;
        ll d, ti;
        cin >> s >> t >> d >> ti;
        --s;
        --t;
 
        dist[s][t] = d;
        dist[t][s] = d;
        tle[s][t] = ti;
        tle[t][s] = ti;
    }
 
    res_c = 0;
    dp.assign(1<<n, vector<ll>(n, -1));
    ll res = solve(0, 0);
 
    if(res == INF) cout << "IMPOSSIBLE" << endl;
    else cout << res << " " << res_c << endl;
 
    return 0;
}