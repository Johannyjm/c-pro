#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, l, p, q, r;
    cin >> n >> m >> l >> p >> q >> r;
    // cout << l/r << l << r << endl;
    // int test[] = {((n/p) * (m/q) * (l/r)), (n/p * m/r * l/q), (n/q * m/p * l/r), (n/q * m/r * l/p), (n/r * m/p * l/q), (n/r * m/q * l/p)};
    // rep(i, 6) cout << test[i] << " ";
    // cout << endl;
    cout << max({((n/p) * (m/q) * (l/r)), ((n/p) * (m/r) * (l/q)), ((n/q) * (m/p) * (l/r)), ((n/q) * (m/r) * (l/p)), ((n/r) * (m/p) * (l/q)), ((n/r) * (m/q) * (l/p))}) << endl;

    return 0;
}