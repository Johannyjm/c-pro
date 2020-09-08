#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, l, p, q, r;
    cin >> n >> m >> l >> p >> q >> r;

    int res = 0;
    res = max(res, (n/p) * (m/q) * (l/r));
    res = max(res, (n/p) * (l/q) * (m/r));
    res = max(res, (m/p) * (n/q) * (l/r));
    res = max(res, (m/p) * (l/q) * (n/r));
    res = max(res, (l/p) * (n/q) * (m/r));
    res = max(res, (l/p) * (m/q) * (n/r));

    cout << res << endl;

    return 0;
}