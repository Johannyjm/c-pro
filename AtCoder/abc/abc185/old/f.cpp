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

    segtree<int, op, e> seg(440000);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, n){
        cin >> a[i];
        seg.set(i, a[i]);
    }

    rep(_, q){
        int t, x, y;
        cin >> t >> x >> y;

        if(t == 1){
            seg.set(x-1, seg.get(x-1)^y);
        }
        else{
            cout << seg.prod(x-1, y) << endl;
        }
    }



    return 0;
}