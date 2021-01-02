#include <bits/stdc++.h>
#include <atcoder/all>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
typedef long long ll;

int op(int a, int b){
    return a+b;
}

int e(){
    return 0;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    segtree<int, op, e> seg(n);
    rep(i, k){
        rep(j, n){
            int l = max(0, j-a[j]);
            int r = min(n-1, j+a[j]);

            seg.
        }
    }

    return 0;
}