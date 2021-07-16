#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<ll> a(m), b(m), c(m);
    rep(i, m) cin >> a[i] >> b[i] >> c[i];

    const ll INF = 1ll << 60;
    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    rep(i, n) dist[i][i] = 0;
    rep(i, m){
        dist[a[i]-1][b[i]-1] = c[i];
    }
    
    ll res = 0;
    rep(k, n) for(int i = n-1; i >= 0; --i) for(int j = n-1; j >= 0; --j){
        if(dist[i][j] != INF) res += dist[i][j];
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
    cout << res << endl;


    return 0;
}