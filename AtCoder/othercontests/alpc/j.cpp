#include <bits/stdc++.h>
#include <atcoder/all>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

int op(int a, int b){
    return max(a, b);
}

int e(){
    return -1;
}

int target;
bool f(int v){
    return v < target;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    segtree<int, op, e> seg(a);
    rep(_, q){
        int com;
        cin >> com;
        if(com == 1){
            int x, v;
            cin >> x >> v;
            --x;

            seg.set(x, v);
        }

        if(com == 2){
            int l, r;
            cin >> l >> r;
            --l;

            cout << seg.prod(l, r) << "\n";
        }

        if(com == 3){
            int p;
            cin >> p >> target;
            --p;

            cout << seg.max_right<f>(p) + 1 << "\n";
        }
    }

    return 0;
}