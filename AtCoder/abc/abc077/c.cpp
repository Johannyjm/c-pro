#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    ll res = 0;
    for(auto y: b){
        ll idx_x = lower_bound(a.begin(), a.end(), y) - a.begin();
        ll idx_z = upper_bound(c.begin(), c.end(), y) - c.begin();

        res += idx_x * (n-idx_z);
    }

    cout << res << endl;

    return 0;
}