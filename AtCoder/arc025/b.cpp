#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;


vector<vector<ll>> sm1, sm2;
ll calc_cost1(int h1, int w1, int h2, int w2){
    // calc: w - x - y + z
    if(h1 > h2) swap(h1, h2);
    if(w1 > w2) swap(w1, w2);
    ll w = sm1[h2][w2];
    ll x = 0;
    ll y = 0;
    ll z = 0;
    if(h1 != 0) x = sm1[h1-1][w2];
    if(w1 != 0) y = sm1[h2][w1-1];
    if(h1!=0 && w1!=0) z = sm1[h1-1][w1-1];

    return w - x - y + z;
}


ll calc_cost2(int h1, int w1, int h2, int w2){
    // calc: w - x - y + z
    if(h1 > h2) swap(h1, h2);
    if(w1 > w2) swap(w1, w2);
    ll w = sm2[h2][w2];
    ll x = 0;
    ll y = 0;
    ll z = 0;
    if(h1 != 0) x = sm2[h1-1][w2];
    if(w1 != 0) y = sm2[h2][w1-1];
    if(h1!=0 && w1!=0) z = sm2[h1-1][w1-1];

    return w - x - y + z;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    vector<vector<ll>> a(h, vector<ll>(w)), b(h, vector<ll>(w));
    rep(i, h) rep(j, w){
        ll c;
        cin >> c;
        if((i+j) % 2 == 0){
            a[i][j] = c;
            b[i][j] = 0;
        }
        else{
            a[i][j] = 0;
            b[i][j] = c;
        }
    }
    sm1.assign(h, vector<ll>(w, 0));
    sm2.assign(h, vector<ll>(w, 0));

    rep(i, h){
        sm1[i][0] = a[i][0];
        sm2[i][0] = b[i][0];
    }
    rep(i, h) rep1(j, w){
        sm1[i][j] = sm1[i][j-1] + a[i][j];
        sm2[i][j] = sm2[i][j-1] + b[i][j];
    }
    rep1(i, h) rep(j, w){
        sm1[i][j] += sm1[i-1][j];
        sm2[i][j] += sm2[i-1][j];
    }

    int res = 0;
    rep(i1, h) rep(j1, w) rep(i2, h) rep(j2, w){
        if(calc_cost1(i1, j1, i2, j2) == calc_cost2(i1, j1, i2, j2)){
            res = max(res, (abs(i2-i1)+1)*(abs(j2-j1)+1));
        }
    }

    cout << res << endl;


    return 0;
}