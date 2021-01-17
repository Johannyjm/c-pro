#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

int op(int a, int b){
    return a ^ b;
}

int e(){
    return 0;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    segtree<int, op, e> seg(330000);
    rep(i, n){
        int a;
        cin >> a;
        seg.set(i, a);
    }

    rep(_, q){
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 1){
            --x;
            seg.set(x, seg.get(x) ^ y);
        }
        if(t == 2){
            --x;
            --y;
            cout << seg.prod(x, y+1) << endl;
        }
    }

    return 0;
}