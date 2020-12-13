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

    segtree<int, op, e> seg(3300000);
    int n, q;
    cin >> n >> q;
    rep(i, n){
        int a;
        cin >> a;
        seg.set(i, a);
    }

    rep(_, q){
        int cmd, x, y;
        cin >> cmd >> x >> y;

        if(cmd == 2){
            cout << seg.prod(x-1, y) << endl;
        }
        if(cmd == 1){
            seg.set(x-1, seg.get(x-1) ^ y);
        }
    }



    return 0;
}