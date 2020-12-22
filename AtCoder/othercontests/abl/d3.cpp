#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

int op(int a, int b){
    return max(a, b);
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

    segtree<int, op, e> dp(330000);
    rep(i, n){
        int l = max(0, a[i]-k);
        int r = min(300000, a[i]+k);
        int val = dp.prod(l, r+1);
        dp.set(a[i], val+1);
    }

    cout << dp.all_prod() << endl;

    return 0;
}