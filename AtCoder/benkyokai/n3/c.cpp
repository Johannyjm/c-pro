#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

ll gcd(ll m, ll n){
    ll tmp;
    while(m%n){
        tmp = n;
        n = m % n;
        m = tmp;
    }
    return n;
}
ll lcm(ll m, ll n){
    return m / gcd(m, n) * n;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h1, w1;
    cin >> h1 >> w1;
    vector<vector<int>> a1(h1, vector<int>(w1));
    rep(i, h1) rep(j, w1) cin >> a1[i][j];

    int h2, w2;
    cin >> h2 >> w2;
    vector<vector<int>> a2(h2, vector<int>(w2));
    rep(i, h2) rep(j, w2) cin >> a2[i][j];

    int hgcd = lcm(h1, h2);
    int wgcd = lcm(w1, w2);

    int alpha = hgcd / h1;
    int beta = wgcd / w1;
    vector<vector<int>> b1(h1*alpha, vector<int>(w1*beta));
    rep(i, h1*alpha) rep(j, w1*beta){
        b1[i][j] = a1[i/alpha][j/beta];
    }

    alpha = hgcd / h2;
    beta = wgcd / w2;
    vector<vector<int>> b2(h2*alpha, vector<int>(w2*beta));
    rep(i, h2*alpha) rep(j, w2*beta){
        b2[i][j] = a2[i/alpha][j/beta];
    }

    rep(i, hgcd){
        rep(j, wgcd) cout << b1[i][j] << " ";
        cout << endl;
    }

    cout << endl;

    rep(i, hgcd){
        rep(j, wgcd) cout << b2[i][j] << " ";
        cout << endl;
    }

    return 0;
}