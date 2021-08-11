#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, l;
    cin >> n >> l;

    vector<ll> dp(n+1, 0);
    dp[0] = 1;
    const ll mod = 1000000007;

    for(int i = 0; i < n; ++i){
        dp[i+1] += dp[i];
        dp[i+1] %= mod;

        if(i + l <= n){
            dp[i+l] += dp[i];
            dp[i+l] %= mod;
        }
    }

    cout << dp[n] << endl;

    return 0;
}
