#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> l(k), r(k);
    rep(i, k) cin >> l[i] >> r[i];

    const int mod = 998244353;
    vector<int> dp(n+1, 0), dps(n+1, 0);
    dp[1] = dps[1] = 1;
    for(int i = 2; i <= n; ++i){
        rep(j, k){
            dp[i] = (dp[i] + (((i-l[j]>=0)?dps[i-l[j]]: 0)%mod +mod - ((i-r[j]-1>=0)?dps[i-r[j]-1]: 0))%mod) % mod;
        }
        dps[i] = (dps[i-1] + dp[i]) % mod;
    }

    

    cout << dp[n] << endl;

    return 0;
}