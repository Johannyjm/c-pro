#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, sx, sy, tx, ty;
    cin >> n >> sx >> sy >> tx >> ty;

    vector<ll> x(n), y(n), r(n);
    rep(i, n) cin >> x[i] >> y[i] >> r[i];

    int s = -1;
    int t = -1;
    rep(i, n){
        ll dists2 = (sx-x[i])*(sx-x[i]) + (sy-y[i])*(sy-y[i]);
        ll distt2 = (tx-x[i])*(tx-x[i]) + (ty-y[i])*(ty-y[i]);

        if(dists2 == r[i]*r[i]) s = i;
        if(distt2 == r[i]*r[i]) t = i;
    }

    vector<vector<int>> g(n);
    rep(fr, n) rep(to, n){
        ll d2 = (x[fr]-x[to])*(x[fr]-x[to]) + (y[fr]-y[to])*(y[fr]-y[to]);
        ll r1 = (r[fr]+r[to])*(r[fr]+r[to]);
        ll r2 = (r[fr]-r[to])*(r[fr]-r[to]);

        if(r2 <= d2 && d2 <= r1){
            g[fr].push_back(to);
            g[to].push_back(fr);
        }
    }

    queue<int> q;
    q.push(s);

    const int INF = 1001001001;
    vector<int> dist(n, INF);
    dist[s] = 0;

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for(auto nv: g[v]){
            if(dist[nv] != INF) continue;

            dist[nv] = dist[v] + 1;
            q.push(nv);
        }
    }

    if(dist[t] != INF) puts("Yes");
    else puts("No");

    return 0;
}