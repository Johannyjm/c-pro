#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m, R;
    cin >> n >> m >> R;
    vector<ll> r(R);
    rep(i, R){
        cin >> r[i];
        --r[i];
    }

    const ll INF = 1ll << 60;
    vector<vector<ll>> cost(n, vector<ll>(n, INF));
    vector<vector<int>> g(n);
    rep(i, m){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
        cost[a][b] = c;
        cost[b][a] = c;
    }

    rep(i, n) cost[i][i] = 0;
    rep(k, n) rep(i, n) rep(j, n){
        cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
    }


    // rep(i, n){
    //     rep(j, n) cout << cost[i][j] << " ";
    //     cout << endl;
    // }

    sort(r.begin(), r.end());

    ll res = INF;
    do{
        ll sm = 0;
        rep1(i, R) sm += cost[r[i-1]][r[i]];

        res = min(res, sm);
    } while(next_permutation(r.begin(), r.end()));


    cout << res << endl;

    return 0;
}