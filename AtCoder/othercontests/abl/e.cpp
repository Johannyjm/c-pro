#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;

struct S{
    mint x;
    mint w;
    S(mint x=0, mint w=1): x(x), w(w) {}
};

S op(S a, S b){
    return S(
        a.x*b.w + b.x, 
        a.w * b.w
    );
}

S e(){
    return S();
}

S mapping(int f, S a){
    if(f == 0) return a;
    return S((a.w-1)/9 * f, a.w);
}

int composition(int f, int g){
    if(f == 0) return g;
    return f;
}

int id(){
    return 0;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    lazy_segtree<S, op, e, int, mapping, composition, id> seg(n);
    rep(i, n) seg.set(i, S(1, 10));

    rep(_, q){
        int l, r, d;
        cin >> l >> r >> d;
        --l;

        seg.apply(l, r, d);

        cout << seg.all_prod().x.val() << endl;
    }

    return 0;
}