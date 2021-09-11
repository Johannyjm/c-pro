#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

ll op(ll a, ll b){
    return a + b;
}

ll e(){
    return 0;
}

ll target;
bool f(ll v){
    return v < target;
}


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll l, q;
    cin >> l >> q;

    segtree<ll, op, e> seg(2 * q);
    seg.set(q, l);

    rep(_, q){
        int c;
        cin >> c;

        if(c == 1){
            ll x;
            cin >> x;
            int idx = seg.max_right<f>(x);
            cout << idx << endl;
        }
    }

    return 0;
}