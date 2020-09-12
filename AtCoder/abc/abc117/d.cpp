#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

vector<ll> tobin(ll num){
    vector<ll> ret;
    while(num){
        ret.push_back(num%2);
        num /= 2;
    }
    reverse(ret.begin(), ret.end());

    return ret;
}

ll dp[60][2];

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, s;
    cin >> n >> s;

    vector<ll> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    vector<ll> sb = tobin(s);
    int l = sb.size();

    if(s == 0){
        ll res = 0;
        for(int i = 0; i < n; ++i) res += 0^a[i];
        cout << res << endl;

        return 0;
    }

    for(int i = 0; i < l; ++i){
        int D = sb[i];
        int bit = n-i-1;
        
        ll xxor0 = 0;
        for(int idx = 0; idx < n; ++idx) xxor0 += 1^((a[idx] & (1ll<<bit))? 1: 0);
        ll xxor1 = 0;
        for(int idx = 0; idx < n; ++idx) xxor1 += 0^((a[idx] & (1ll<<bit))? 1: 0);
        
        if(i==0){
            dp[i+1][0] = D? xxor1: xxor0;
            dp[i+1][1] = D? xxor0: 0;
            continue;
        }
        
        for(int j = 0; j < 2; ++j){
            
            if(j == 1){
                dp[i+1][j] = (dp[i][1] << 1) + max(xxor0, xxor1);
                if(D==1) dp[i+1][j] = max(dp[i+1][j], (dp[i][0] << 1) + xxor0);
            }
            else{
                dp[i+1][j] = (dp[i][j] << 1) + (D? xxor1: xxor0);
            }

        }
    }

    cout << max(dp[l][0], dp[l][1]) << endl;

    return 0;
}
