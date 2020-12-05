#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int n, m;
vector<ll> x, y, z;

ll calc(vector<int> idxs){
    ll smx = 0;
    ll smy = 0;
    ll smz = 0;

    for(auto i: idxs){
        smx += x[i];
        smy += y[i];
        smz += z[i];        
    }

    return abs(smx) + abs(smy) + abs(smz);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    x.resize(n);
    y.resize(n);
    z.resize(n);
    vector<pair<ll, int>> xi(n), yi(n), zi(n);
    rep(i, n){
        cin >> x[i] >> y[i] >> z[i];
        xi[i] = {x[i], i};
        yi[i] = {y[i], i};
        zi[i] = {z[i], i};
    }

    if(m==0){
        cout << 0 << endl;
        return 0;
    }

    sort(xi.begin(), xi.end());
    sort(yi.begin(), yi.end());
    sort(zi.begin(), zi.end());

    ll res = -(1ll<<60);
    
    vector<int> idxs;
    rep(i, m){
        idxs.push_back(xi[i].second);
    }
    res = max(res, calc(idxs));

    idxs.clear();
    for(int i = n-1; i > n-1-m; --i){
        idxs.push_back(xi[i].second);
    }
    res = max(res, calc(idxs));

    idxs.clear();
    rep(i, m){
        idxs.push_back(yi[i].second);
    }
    res = max(res, calc(idxs));

    idxs.clear();
    for(int i = n-1; i > n-1-m; --i){
        idxs.push_back(yi[i].second);
    }
    res = max(res, calc(idxs));

    idxs.clear();
    rep(i, m){
        idxs.push_back(zi[i].second);
    }
    res = max(res, calc(idxs));

    idxs.clear();
    for(int i = n-1; i > n-1-m; --i){
        idxs.push_back(zi[i].second);
    }
    res = max(res, calc(idxs));

    cout << res << endl;

    return 0;
}