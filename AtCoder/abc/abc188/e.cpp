#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;
const ll INF = 1ll<<60;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<int>> g(n);
    rep(i, m){
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        g[x].push_back(y);
    }

    vector<ll> dp(n, INF);
    rep(v, n){
        for(int nv: g[v]){
            dp[nv] = min({a[v], dp[v], dp[nv]});
        }
    }

    ll res = -INF;
    rep(i, n){
        res = max(res, a[i] - dp[i]);
    }

    cout << res << endl;

    return 0;
}