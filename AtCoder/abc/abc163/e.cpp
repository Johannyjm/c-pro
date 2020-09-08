#include <bits/stdc++.h>
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

    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    
    rep(i, n) rep(j, n){
        dp[i][j] = a[i] * abs(i - j);
    }

    cout << endl;
    rep(i, n){
        rep(j, n) cout << dp[i][j] << " ";
        cout << endl;
    }

    vector<vector<pair<ll, ll>>> ord(n, vector<pair<ll, ll>>(n));
    rep(i, n){
        rep(j, n){
            ord[i][j] = make_pair(dp[i][j], j);
        }
        sort(ord[i].begin(), ord[i].end(), greater<pair<ll, ll>>());
    }

    rep(i, n) {
        rep(j, n) cout << ord[i][j].first << ord[i][j].second << " ";
        cout << endl;
    
    }

    vector<pair<ll, ll>> mxs(n);
    rep(i, n) mxs[i] = make_pair(ord[i][0].first, i);

    sort(mxs.begin(), mxs.end(), greater<pair<ll, ll>>());
    rep(i, n) cout << mxs[i].first << " " << mxs[i].second << endl;;
    cout << endl;

    ll res = 0;
    vector<ll> used(n, false);
    rep(i, n){
        if(!used[ord[mxs[i].second][0].second]){
            res += mxs[i].first;
            used[ord[mxs[i].second][0].second] = true;
        }
        else{
            int cnt = 1;
            while(used[ord[mxs[i].second][cnt].second]){
                ++cnt;
            }
            res += ord[mxs[i].second][cnt].first;
        }
    }

    cout << res << endl;

    return 0;
}