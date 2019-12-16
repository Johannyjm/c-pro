#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll MOD = 1e9+7;
    // ll a[n];
    // for (ll i = 0; i < n; ++i) cin >> a[i];
    // 

    // ll res = 0;

    // for (ll i = 0; i < n-1; ++i){
    //     for(ll j = i+1; j < n; ++j){
    //         res += ((a[i]%MOD) ^ (a[j]% MOD)) % MOD; 
    //     }
    // }

    // cout << res << endl;

    int sum[60] = {0};

    for(ll i = 0; i < n; ++i){
        ll a;
        cin >> a;
        for(int j = 0; j < 60; ++j){
            sum[j] += a%2;
            a /= 2;
            
        }
        for (int j = 0; j < 60; ++j) cout << sum[j] << " ";
        cout << endl;

    }
    ll res = 0;
    for (int i = 0; i < 60; ++i){
        if(sum[i]%2) res = ((res%MOD) + (1<<i)%MOD)%MOD;
    }
    cout << res << endl;

}