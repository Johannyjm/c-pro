#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll a, b, m;
    cin >> a >> b >> m;
    vector<ll> as(a), bs(b);
    ll min_a = 100001;
    ll min_b = 100001;
    rep(i, a) {
        ll tmp;
        cin >> tmp;
        as[i] = tmp;
        min_a = min(min_a, tmp);
    }
    rep(i, b) {
        ll tmp;
        cin >> tmp;
        bs[i] = tmp;
        min_b = min(min_b, tmp);
    }

    ll res = min_a + min_b;
    rep(i, m){
        ll x, y, c;
        cin >> x >> y >> c;
        --x;
        --y;
        res = min(as[x]+bs[y]-c, res);
    }

    cout << res << endl;

    return 0;
}