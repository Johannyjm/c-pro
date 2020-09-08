#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll h, n;
    cin >> h >> n;

    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    vector<ll> dp(h+10001, INF);
    dp[0] = 0;

    rep(i, h+10001){
        rep(j, n){
            if(i-a[j] < 0) continue;
            dp[i] = min(dp[i-a[j]] + b[j], dp[i]);
            
        }
    }

    ll res = INF;
    for(int i = h; i < h+10001; ++i){
        res = min(res, dp[i]);
    }

    cout << res << endl;

    return 0;
}