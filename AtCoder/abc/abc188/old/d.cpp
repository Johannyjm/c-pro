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

    ll n, C;
    cin >> n >> C;

    vector<ll> a(n), b(n), c(n);
    vector<ll> ranges;
    rep(i, n){
        cin >> a[i] >> b[i] >> c[i];
        ranges.push_back(a[i]);
        ranges.push_back(b[i]);
        ranges.push_back(b[i]+1);
    }

    vector<ll> origin = ranges;
    compress(ranges);

    map<ll, ll> cnv;
    rep(i, (int)ranges.size()){
        cnv[ranges[i]] = origin[i];
    }

    for(auto e: origin) cout << e << " ";
    cout << endl;
    for(auto e: ranges) cout << e << " ";
    cout << endl;

    // for(auto k: cnv) cout << k.first << " " << k.second << endl;
    // cout << endl;

    vector<ll> sm(440000, 0);
    rep(i, n){
        sm[ranges[2*i]] += c[i];
        sm[ranges[2*i+1] + 1] -= c[i];
    }

    rep(i, 430000) sm[i+1] += sm[i];

    rep(i, 4) cout << sm[i] << " ";
    cout << endl;

    ll res = 0;
    ll last = 0;
    rep(i, 430000){
        // if(i < 10) cout << cnv[i+1] << " " << cnv[i] << endl;
        if(cnv[i+1] == 0) break;
        ll seg = cnv[i+1] - cnv[i];

        res += seg * min(C, sm[i]);
        // if(sm[i] > sm[i+1]) res += min(C, sm[i]);
        // if(i < 10) cout << res << " " << seg << " " << sm[i] << endl;
        if(sm[i+1] != 0) last = sm[i+1];
    }

    res += min(C, last);
    cout << last << endl;
    cout << res << endl;


    // vector<pair<ll, ll>> range(n);
    // rep(i, n){
    //     cin >> a[i] >> b[i] >> c[i];
    //     range[i] = {a[i], i};
    // }

    // sort(range.begin(), range.end());

    // ll res = 0;
    // rep(i, n-1){
    //     int idx = range[i].second;
    //     ll l = range[i].first;
    //     ll r = range[i+1].first;

    //     res += (r-l) * min(c[idx], C);

    // }

    return 0;
}