#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;
    
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    const int mxd = 50;
    vector<vector<ll>> dp(100, vector<ll>(2, -1));

    dp[0][0] = 0;
    for(int d = 0; d < mxd; ++d){
        ll mask = 1ll << (mxd-d-1);

        int num = 0;
        for(int i = 0; i < n; ++i) if(a[i] & mask) ++num;
        
        ll xxor0 = mask*num;
        ll xxor1 = mask*(n-num);

        if(dp[d][1] != -1){
            dp[d+1][1] = max(dp[d+1][1], dp[d][1] + max(xxor0, xxor1));
        }

        if(dp[d][0] != -1){
            if(k & mask){
                dp[d+1][1] = max(dp[d+1][1], dp[d][0] + xxor0);
            }
        }
        if(dp[d][0] != -1){
            if(k & mask) dp[d+1][0] = max(dp[d+1][0], dp[d][0] + xxor1);
            else dp[d+1][0] = max(dp[d+1][0], dp[d][0] + xxor0);
        }
    }

    cout << max(dp[mxd][0], dp[mxd][1]) << endl;

    return 0;
}
