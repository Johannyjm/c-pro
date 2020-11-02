#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int n;
vector<ll> r, c;
ll dp[110][110];
const ll INF = 1ll<<60;

ll rec(int i, int j){
    if(dp[i][j] > 0) return dp[i][j];
    if(j-i == 1) return 0;
    if(j-i == 2) return dp[i][j] = r[i] * c[i] * c[j-1];

    ll ret = INF;
    for(int m = i+1; m < j; ++m){
        ret = min(ret, rec(i, m)+rec(m, j)+r[i]*c[m-1]*c[j-1]);
        // cout << i << " " << m << " " << j << " " << ret << endl;
    }

    return dp[i][j] = ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    r.resize(n);
    c.resize(n);
    rep(i, n) cin >> r[i] >> c[i];

    cout << rec(0, n) << endl;

    // rep(i, n+1){
    //     rep(j, n+1) cout << dp[i][j] << " ";
    //     cout << endl;
    // }

    return 0;
}