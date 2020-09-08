#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1ll << 60;
 
int n;
vector<vector<ll>> dist;
vector<vector<ll>> tle;
 
vector<vector<pair<ll, ll>>> dp;
pair<ll, ll> solve(int s, int v){
    if(dp[s][v].first >= 0){
        return dp[s][v];
    }
    if(s==(1<<n)-1 && v==0){
        return make_pair(0, 1);
    }
 
    ll ret = INF;
    rep(nv, n){
        if(!(s & (1<<nv))){
            pair<ll, ll> np = solve(s|(1<<nv), nv);
            if(tle[v][nv] < np.first + dist[v][nv]) continue;
            
            if(np.first + dist[v][nv] == ret) dp[s][v].second += np.second;
            if(np.first + dist[v][nv] < ret) {
                ret = np.first + dist[v][nv];
                dp[s][v].second = np.second;
            }
        }
    }
 
    dp[s][v].first = ret;
 
    return dp[s][v];
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
 
    dp.assign(1<<n, vector<pair<ll, ll>>(n, make_pair(-1, 0)));
    pair<ll, ll> res = solve(0, 0);
 
    if(res.first == INF) cout << "IMPOSSIBLE" << endl;
    else cout << res.first << " " << res.second << endl;
 
    return 0;
}