#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> a(n, vector<ll>(m));
    rep(i, n) rep(j, m) cin >> a[i][j];

    ll res = 0;
    rep(one, m){
        rep(two, m) {
            ll sum = 0;
            rep(i, n){
                sum += max(a[i][one], a[i][two]);
            }
            res = max(res, sum);
        }
    }

    cout << res << endl;

    return 0;
}