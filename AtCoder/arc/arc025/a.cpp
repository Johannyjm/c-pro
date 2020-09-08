#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<int> d(7);
    vector<int> j(7);

    rep(i, 7) cin >> d[i];
    rep(i, 7) cin >> j[i];

    int res = 0;
    rep(i, 7) res += max(d[i], j[i]);

    cout << res << endl;

    return 0;
}