#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    vector<ll> a(3*n);
    rep(i, 3*n) cin >> a[i];

    sort(a.begin(), a.end(), greater<ll>());
    ll res = 0;
    rep(i, n) res += a[2*i+1];

    cout << res << endl;

    return 0;
}