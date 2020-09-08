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

    vector<pair<ll, ll>> ab(n);
    rep(i, n){
        ll a, b;
        cin >> a >> b;
        
        ab[i] = make_pair(a, b);
    }

    vector<vector<ll>> dp(n+1, vector<ll>(h+1, INF));
    dp[0][0] = 0;

    rep(i, n){
        rep(j, h+1){
            dp[i+1][j] = min(dp[i][j], dp[i+1][j]);
            if(i>=ab[i].first) dp[i+1][j] = min(dp[i+1][j], dp[i+1][j-ab[i].first] - ab[i].second);
        }
    }

    cout << dp[n][h] << endl;


    return 0;
}