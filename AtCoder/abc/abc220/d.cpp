#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<vector<mint>> dp(n+1, vector<mint>(10, 0));
    // rep(i, 10) dp[0][i] = 1;
    // // vector<deque<int>> dq(n);
    // // rep(i, 10) rep(j, n) dq[i].push_back(a[j]);

    // deque<int> dq;
    // rep(i, n) dq.push_back(a[i]);

    // rep(i, n){
    //     int l = dq.front();
    //     dq.pop_front();
    //     int r = dq.back();
    //     dq.pop_back();

    //     dp[i+1][(l+r)%10] += dp[i][l]
    // }

    dp[0][a.front()] = 1;

    // reverse(a.begin(), a.end());

    rep(i, n-1){
        rep(j, 10){
            dp[i+1][(a[i+1]+j)%10] += dp[i][j];
            dp[i+1][(a[i+1]*j)%10] += dp[i][j];
        }
    }

    // rep(i, n+1){
    //     rep(j, 10) cout << dp[i][j].val() << " ";
    //     cout << endl;
    // }

    rep(i, 10) cout << dp[n-1][i].val() << endl;

    return 0;
}