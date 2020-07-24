#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll INF = 1ll << 60;
ll n, m;
vector<vector<ll>> cost, limit;
vector<vector<pair<ll, ll>>> dp;

pair<ll, ll> rec(ll s, ll v){
    if(dp[s][v].first != 0) return dp[s][v];
    if(s == (1<<n)-1 && v==0) return make_pair(0, 1);

    pair<ll, ll> ret = make_pair(1ll<<60, 0);
    for(int nv = 0; nv < n; ++nv){
        if(s & (1<<nv)) continue;
        if(cost[v][nv] == INF) continue;
        pair<ll, ll> tmp = rec(s|(1<<nv), nv);
        if(tmp.first + cost[v][nv] > limit[v][nv]) continue;
        if(tmp.first + cost[v][nv] == ret.first) ret.second += tmp.second;
        if(tmp.first + cost[v][nv] < ret.first){
            ret.first = tmp.first + cost[v][nv];
            ret.second = tmp.second;
        } 
    }
    dp[s][v] = ret;
    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    cost.resize(n, vector<ll>(n, INF));
    limit.resize(n, vector<ll>(n, 0));

    for(int i = 0; i < m; ++i){
        int from, to;
        ll d, t;
        cin >> from >> to >> d >> t;
        --from;
        --to;
        cost[from][to] = d;
        cost[to][from] = d;
        limit[from][to] = t;
        limit[to][from] = t;
    }

    dp.resize((1<<n), vector<pair<ll, ll>>(n, make_pair(0, 0)));
    pair<ll, ll> res = rec(0, 0);

    if(res.first == INF) cout << "IMPOSSIBLE" << endl;
    else cout << res.first << " " << res.second << endl;

}
