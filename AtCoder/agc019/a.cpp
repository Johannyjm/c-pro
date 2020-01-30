#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll q, h, s, d, n;
    cin >> q >> h >> s >> d >> n;
    vector<ll> c = {1, 2, 4, 8};
    vector<ll> v = {q, h, s, d};

    n *= 4;

    vector<ll> dp(n+1, INF);
    dp[0] = 0;
    rep(i, n+1){
        rep(j, 4){
            if(i-c[j] < 0) continue;
            dp[i] = min(dp[i], dp[i-c[j]] + v[j]);
        }
    }

    // rep(i, n+1) cout << dp[i] << " ";
    // cout << endl;

    cout << dp[n] << endl;


    return 0;
}