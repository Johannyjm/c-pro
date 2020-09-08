#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;

    vector<int> p(a);
    vector<int> q(b);
    vector<int> r(c);

    rep(i, a) cin >> p[i];
    rep(i, b) cin >> q[i];
    rep(i, c) cin >> r[i];

    sort(p.begin(), p.end(), greater<int>());
    rep(i, x) r.push_back(p[i]);

    sort(q.begin(), q.end(), greater<int>());
    rep(i, y) r.push_back(q[i]);

    sort(r.begin(), r.end(), greater<int>());

    int res = 0;
    rep(i, x+y) res += r[i];

    cout << res << endl;

    return 0;
}