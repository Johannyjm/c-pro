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

    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<mint> sm(n-1, 0);
    sm[n-2] = a.back();
    for(int i = n-3; i >= 0; --i){
        sm[i] = sm[i+1] + a[i+1];
    }

    // rep(i, n-1) cout << sm[i].val() << endl;

    mint res = 0;
    rep(i, n-1){
        res += a[i] * sm[i];
    }

    cout << res.val() << endl;

    return 0;
}