#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, q;
    string s;
    cin >> n >> q >> s;

    vector<ll> dp(n, 0);
    rep(i, s.size()-1){
        if(s[i]=='A' && s[i+1]=='C') dp[i+1] = dp[i] + 1;
        else dp[i+1] = dp[i];
    }

    rep(i, n) cout << dp[i] << " ";
    cout << endl;

    rep(i, q){
        ll l, r;
        cin >> l >> r;
        --l;
        --r;

        cout << dp[r] - dp[l] << endl;
    }

    return 0;
}