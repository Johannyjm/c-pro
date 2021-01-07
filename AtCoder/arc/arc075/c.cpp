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

    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<ll> s(n+1, 0);
    rep(i, n){
        s[i+1] = s[i] + a[i];
    }

    vector<ll> b(n+1);
    rep(i, n+1){
        b[i] = k*i - s[i];
    }

    compress(b);
    // for(auto e: b) cout << e << " ";
    // cout << endl;

    fenwick_tree<int> fw(220000);
    ll res = 0;
    rep(i, n+1){
        res += i - fw.sum(0, b[i]);
        fw.add(b[i], 1);
    }

    cout << res << endl;


    return 0;
}