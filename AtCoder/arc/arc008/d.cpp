#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

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

pair<double, double> op(pair<double, double> a, pair<double, double> b){
    return {a.first*b.first, a.second*b.first+b.second};
}

pair<double, double> e(){
    return {1, 0};
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    vector<ll> p(m);
    vector<double> a(m), b(m);
    rep(i, m) cin >> p[i] >> a[i] >> b[i];

    vector<ll> vals = compress(p);
    
    segtree<pair<double, double>, op, e> seg(110000);
    double res1 = 1;
    double res2 = 1;

    rep(i, m){
        seg.set(p[i], {a[i], b[i]});
        pair<double, double> prod = seg.all_prod();
        
        res1 = min(res1, prod.first + prod.second);
        res2 = max(res2, prod.first + prod.second);
    }

    cout << setprecision(20);
    cout << res1 << "\n" << res2 << endl;

    return 0;
}