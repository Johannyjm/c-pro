#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    map<ll, ll> start;
    rep(i, n){
        if(i - a[i] >= 0) ++start[i - a[i] + 1];
    }
    // rep(i, n) cout << start[i] << " ";
    // cout << endl;

    vector<ll> dp(n);
    for(ll i = 0; i < n; ++i){
        dp[i] = i + a[i] + 1;
    }

    // rep(i, n) cout << dp[i] << " ";
    // cout << endl;

    ll res = 0;
    rep(i, n){
        res += start[dp[i]];
    }

    cout << res << endl;

    return 0;
}