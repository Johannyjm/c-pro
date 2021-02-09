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

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, d, a;
    cin >> n >> d >> a;

    vector<ll> x(n), h(n);
    vector<pair<ll, ll>> xh(n);
    rep(i, n){
        cin >> x[i] >> h[i];
        xh[i] = {x[i], h[i]};
    }
    
    sort(xh.begin(), xh.end());

    vector<ll> events;
    rep(i, n){
        events.push_back(max(xh[i].first - d, 0ll));
        events.push_back(xh[i].first + d);
    }

    vector<ll> orig = events;
    compress(events);

    unordered_map<ll, ll> cnv;
    rep(i, (int)events.size()){
        cnv[orig[i]] = events[i];
    }

    fenwick_tree<ll> bit(1000000);
    ll res = 0;
    rep(i, n){
        ll hits = bit.sum(cnv[xh[i].first-d], cnv[xh[i].first+d]+1);
        if(xh[i].second - hits > 0){
            ll now = xh[i].second - hits;
            ll cnt = ((now + a - 1)/a);
            res += cnt;
            ll damage = cnt * a;
            bit.add(cnv[xh[i].first + d], damage);
        }
    }

    cout << res << endl;


    return 0;
}