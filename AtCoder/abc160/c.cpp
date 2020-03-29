#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int k, n, l;
    cin >> k >> n;

    vector<int> a(n);
    vector<int> dif(n);
    rep(i, n) cin >> a[i];

    dif[0] = a[0] + (k - a[n-1]);
    rep1(i, n) dif[i] = a[i] - a[i-1];

    int d_max = -1;
    rep(i, n) d_max = max(d_max, dif[i]);

    cout << k - d_max << endl;

    return 0;
}