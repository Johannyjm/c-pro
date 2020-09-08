#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;

    vector<ll> a(k), b(k);
    map<ll, ll> mp;
    rep(i, k) {
        cin >> a[i] >> b[i];
        --a[i];
        mp[a[i]] = b[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(3, 0));
    if(mp[0] > 0) {
        rep(i, 3){
            if(mp[0] == i+1) dp[0][i] = 1;
            else dp[0][i] = -1;
        }
    }
    else{
        rep(i, 3) dp[0][i] = 1;
    }

    if(mp[1] > 0){
        rep(i, 3){
            if(mp[1] == i+1) {
                rep(j, 3){
                    if(dp[0][j] >= 0) dp[1][i] += dp[0][j];
                }
            }
            else dp[1][i] = -1;
        }
    }
    else{
        rep(i, 3){
            rep(j, 3){
                if(dp[0][j] >= 0) dp[1][i] += dp[0][j];
            }
        }
    }

    const ll mod = 10000;
    for(ll d = 2; d < n; ++d){
        ll pp0 = max(dp[d-2][0], 0LL);
        ll pp1 = max(dp[d-2][1], 0LL);
        ll pp2 = max(dp[d-2][2], 0LL);

        ll p0 = max(dp[d-1][0], 0LL);
        ll p1 = max(dp[d-1][1], 0LL);
        ll p2 = max(dp[d-1][2], 0LL);


        if(mp[d] > 0){
            if(mp[d] == 1){
                dp[d][0] = pp0 + p1 + pp0 + p2 + pp1 + p0 + pp1 + p1 + pp1 + p2 + pp2 + p0 + pp2 + p1 + pp2 + p2;
                dp[d][1] = -1;
                dp[d][2] = -1;
            }
            if(mp[d] == 2){
                dp[d][0] = -1;
                dp[d][1] = pp0 + p0 + pp0 + p1 + pp0 + p2 + pp1 + p0 + pp1 + p2 + pp2 + p0 + pp2 + p1 + pp2 + p2;
                dp[d][2] = -1;
            }
            if(mp[d] == 3){
                dp[d][0] = -1;
                dp[d][1] = -1;
                dp[d][2] = pp0 + p0 + pp0 + p1 + pp0 + p2 + pp1 + p0 + pp1 + p1 + pp1 + p2 + pp2 + p0 + pp2 + p1;
            }


        }
    }


    rep(i, n){
        rep(j, 3) cout << dp[i][j] << " ";
        cout << endl;
    }


    return 0;
}