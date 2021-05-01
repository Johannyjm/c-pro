#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> a(n), b(n), c(n), d(n), e(n);
    rep(i, n) cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];

    vector<pair<ll, int>> as(n);
    vector<pair<ll, int>> bs(n);
    vector<pair<ll, int>> cs(n);
    vector<pair<ll, int>> ds(n);
    vector<pair<ll, int>> es(n);
    rep(i, n){
        as[i] = {a[i], i};
        bs[i] = {b[i], i};
        cs[i] = {c[i], i};
        ds[i] = {d[i], i};
        es[i] = {e[i], i};
    }
    
    sort(as.begin(), as.end(), greater<pair<ll, int>>());
    sort(bs.begin(), bs.end(), greater<pair<ll, int>>());
    sort(cs.begin(), cs.end(), greater<pair<ll, int>>());
    sort(ds.begin(), ds.end(), greater<pair<ll, int>>());
    sort(es.begin(), es.end(), greater<pair<ll, int>>());

    auto calc = [&](int i, int j){
        return min({max(a[i], a[j]), max(b[i], b[j]), max(c[i], c[j]), max(d[i], d[j]), max(e[i], e[j])});
    };

    auto calc3 = [&](int i, int j, int k){
        return min({max({a[i], a[j], a[k]}), max({b[i], b[j], b[k]}), max({c[i], c[j], c[k]}), max({d[i], d[j], d[k]}), max({e[i], e[j], e[k]})});
    };

    ll res = 0;
    rep(i, n) rep(j, n){
        int mnmx = calc(i, j);

        if(max(a[i], a[j]) == mnmx){
            if(as[0].second != i && as[0].second != j){
                res = max(res, calc3(i, j, as[0].second));
            }
            if(as[1].second != i && as[1].second != j){
                res = max(res, calc3(i, j, as[1].second));
            }
            if(as[2].second != i && as[2].second != j){
                res = max(res, calc3(i, j, as[2].second));
            }
        }
        if(max(b[i], b[j]) == mnmx){
            if(bs[0].second != i && bs[0].second != j){
                res = max(res, calc3(i, j, bs[0].second));
            }
            if(bs[1].second != i && bs[1].second != j){
                res = max(res, calc3(i, j, bs[1].second));
            }
            if(bs[2].second != i && bs[2].second != j){
                res = max(res, calc3(i, j, bs[2].second));
            }
        }
        if(max(c[i], c[j]) == mnmx){
            if(cs[0].second != i && cs[0].second != j){
                res = max(res, calc3(i, j, cs[0].second));
            }
            if(cs[1].second != i && cs[1].second != j){
                res = max(res, calc3(i, j, cs[1].second));
            }
            if(cs[2].second != i && cs[2].second != j){
                res = max(res, calc3(i, j, cs[2].second));
            }
        }
        if(max(d[i], d[j]) == mnmx){
            if(ds[0].second != i && ds[0].second != j){
                res = max(res, calc3(i, j, ds[0].second));
            }
            if(ds[1].second != i && ds[1].second != j){
                res = max(res, calc3(i, j, ds[1].second));
            }
            if(ds[2].second != i && ds[2].second != j){
                res = max(res, calc3(i, j, ds[2].second));
            }
        }
        if(max(e[i], e[j]) == mnmx){
            if(es[0].second != i && es[0].second != j){
                res = max(res, calc3(i, j, es[0].second));
            }
            if(es[1].second != i && es[1].second != j){
                res = max(res, calc3(i, j, es[1].second));
            }
            if(es[2].second != i && es[2].second != j){
                res = max(res, calc3(i, j, es[2].second));
            }
        }
    }
    
    cout << res << endl;
    

    return 0;
}