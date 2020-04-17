#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<ll> a(n), b(n), c(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    ll res = 0;
    rep(i, n){
        ll mid = b[i];

        ll upper = lower_bound(a.begin(), a.end(), mid) - a.begin();
        ll lower = c.end() - upper_bound(c.begin(), c.end(), mid);

        res += upper * lower;
    }

    cout << res << endl;

    return 0;
}