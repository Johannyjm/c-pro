#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    // vector<vecotr<pair<mint, mint>>> dp(2, vector<pair<mint, mint>>(n+10));
    // dp[0]
    vector<vector<mint>> cnt(n+10, vector<mint>(2, 0));
    cnt[0][0] = 1;
    cnt[0][1] = 1;
    rep1(i, n-1){
        cnt[i][0] = cnt[i-1][0] + cnt[i-1][1];
        cnt[i][1] = cnt[i-1][0];
    }

    vector<vector<mint> dp(n+10, vector<mint>(2, 0));
    dp[0][0] = a[0] * ;


    return 0;
}