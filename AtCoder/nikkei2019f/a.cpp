#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<ll> sm(n+1, 0);
    rep(i, n){
        sm[i+1] = sm[i] + a[i];
    }

    rep(i, n){
        ll res = 0;
        rep(l, n-i){
            int r = l+i;
            ll range_sm = sm[r+1] - sm[l];
            res = max(res, range_sm);
        }
        cout << res << "\n";
    }

    return 0;
}