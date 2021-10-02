#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

template<typename T>
vector<T> compress(vector<T> &a){
    vector<T> ret = a;
    sort(ret.begin(), ret.end());
    ret.erase(unique(ret.begin(), ret.end()), ret.end());
    for(int i = 0; i < (int)a.size(); ++i){
        a[i] = lower_bound(ret.begin(), ret.end(), a[i]) - ret.begin();
    }
    return ret;
}


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    
    vector<ll> fromto;
    rep(i, n){
        fromto.push_back(a[i]);
        fromto.push_back(a[i] + b[i] - 1);
    }

    vector<ll> cnv = compress(fromto);

    // for(auto e: fromto) cout << e << " ";
    // cout << endl;
    // for(auto e: cnv) cout << e << " ";
    // cout << endl;

    vector<int> from, to;
    rep(i, 2*n){
        if(i%2 == 0) from.push_back(fromto[i]);
        else to.push_back(fromto[i]);
    }

    // for(auto e: from) cout << e << " ";
    // cout << endl;
    // for(auto e: to) cout << e << " ";
    // cout << endl;

    vector<ll> imos(220000, 0);
    rep(i, n){
        imos[from[i]] += 1;
        imos[to[i] + 1] -= 1;
    }
    // rep(i, 20) cout << imos[i] << " ";
    // cout << endl;
    rep(i, 210000) imos[i+1] += imos[i];

    rep(i, 20) cout << imos[i] << " ";
    cout << endl;

    vector<ll> res(n+1);
    rep(i, 210000){
        if(imos[i] == 0) continue;
        // if(i < 20){
        //     cout << i << " " << imos[i];
        //     cout << endl;
        // }
        if(imos[i] == imos[i+1]) res[imos[i]] += imos[i]*cnv[i+1];
    }

    rep1(i, n) cout << res[i] << " ";
    cout << res[n] << endl;

    return 0;
}