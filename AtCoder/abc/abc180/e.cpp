#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

ll n;
vector<ll> x, y, z;
ll dp[1ll<<18][20];
const ll INF = 1ll<<60;
ll rec(ll s, ll v){
    if(dp[s][v] != 0) return dp[s][v];
    if(s == (1<<n) - 1 && v==0) return 0;

    ll ret = INF;
    for(ll nv = 0; nv < n; ++nv){
        if(s & (1<<nv)) continue;

        ret = min(ret, rec((s|(1<<nv)), nv) + abs(x[v]-x[nv]) + abs(y[v]-y[nv]) + max(0ll, z[nv]-z[v]));
    }

    return dp[s][v] = ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    x.resize(n);
    y.resize(n);
    z.resize(n);
    rep(i, n) cin >> x[i] >> y[i] >> z[i];

    cout << rec(0, 0) << endl;


    return 0;
}