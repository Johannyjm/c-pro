#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    fenwick_tree<ll> bit(n);
    ll res = 0;
    rep(i, n){
        res += bit.sum(a[i], n);
        bit.add(a[i], 1);
    }

    cout << res << endl;
    rep(i, n-1){
        res -= bit.sum(0, a[i]);
        res += bit.sum(a[i]+1, n);

        cout << res << endl;
    }

    return 0;
}