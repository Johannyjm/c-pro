#include <bits/stdc++.h>
#include <atcoder/all>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, q;
    cin >> n >> q;

    fenwick_tree<ll> bit(n);

    rep(i, n){
        ll a;
        cin >> a;
        bit.add(i, a);
    }

    rep(_, q){
        int cmd;
        cin >> cmd;
        if(cmd == 0){
            int p;
            ll x;
            cin >> p >> x;
            bit.add(p, x);
        }
        else{
            int l, r;
            cin >> l >> r;
            cout << bit.sum(l, r) << endl;
        }
    }

    return 0;
}