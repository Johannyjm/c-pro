#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

vector<vector<ll>> sm;
ll calc_cost(int h1, int w1, int h2, int w2){
    // calc: w - x - y + z
    if(h1 > h2) swap(h1, h2);
    if(w1 > w2) swap(w1, w2);
    ll w = sm[h2][w2];
    ll x = 0;
    ll y = 0;
    ll z = 0;
    if(h1 != 0) x = sm[h1-1][w2];
    if(w1 != 0) y = sm[h2][w1-1];
    if(h1!=0 && w1!=0) z = sm[h1-1][w1-1];

    return w - x - y + z;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll h, w, k, v;
    cin >> h >> w >> k >> v;

    vector<vector<ll>> a(h, vector<ll>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];

    sm.assign(h, vector<ll>(w, 0));
    rep(i, h) sm[i][0] = a[i][0];
    rep(i, h) rep1(j, w) sm[i][j] = sm[i][j-1] + a[i][j];
    rep1(i, h) rep(j, w) sm[i][j] += sm[i-1][j];

    int res = 0;
    rep(h1, h) rep(w1, w){
        for(int h2 = h1; h2 < h; ++h2){
            for(int w2 = w1; w2 < w; ++w2){
                int s = (h2-h1+1) * (w2-w1+1);
                ll cost = calc_cost(h1, w1, h2, w2) + k*s;
                if(cost > v) continue;

                res = max(res, s);
            }
        }
    }

    cout << res << endl;

    return 0;
}