#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];

    sort(h.begin(), h.end());
    ll res = h[k-1] - h[0];
    rep1(i, n-k+1){
        res = min(res, h[k+i-1]-h[i]);
    }

    cout << res << endl;

    return 0;
}