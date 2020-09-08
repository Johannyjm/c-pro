#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
const int MOD = 1000000007;

ll fact_mod(ll num){
    if(num==0) return 1;

    ll ret = 1;
    rep1(i, num){
        i %= MOD;
        ret = ret * i % MOD;
    }
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<ll> right_smaller(n);
    rep(i, n-1){
        ll cnt = 0;
        for(int j = i+1; j<n; ++j){
            if(a[i]>a[j]) ++cnt;
        }
        right_smaller[i] = cnt;
    }

    vector<ll> all_smaller(n);
    rep(i, n){
        ll cnt = 0;
        rep(j, n){
            if(a[i]>a[j]) ++cnt;
        }
        all_smaller[i] = cnt;
    }

    ll res = 0;
    ll FACT = fact_mod(k-1);
    rep(i, n){
        if(all_smaller[i]==0) continue;
        res = ((res + (right_smaller[i]%MOD * k%MOD) % MOD) % MOD + (all_smaller[i]%MOD) * FACT % MOD) % MOD;
    }

    cout << res << endl;

    
    // rep(i, n) cout << right_smaller[i] << " ";
    // cout << endl;
    // rep(i, n) cout << all_smaller[i] << " ";
    // cout << endl;

    // vector<vector<int>> smaller(n, vector<int>(n));
    // rep(i, n){
    //     rep(j, n){
    //         if(a[i]>=a[j]){
    //             if(a[i]==a[j]) smaller[i][j] = -1;
    //             else smaller[i][j] = 0;
    //         }
    //         else smaller[i][j] = 1;
    //     }
    // }

    // rep(i, n) {
    //     rep(j, n) cout << smaller[i][j] << " ";
    //     cout << endl;
    // }

    // ll res  = 0;
    // rep(i, n) res = (res + right_smaller[i]) % MOD;
    // k %= MOD;
    
    // cout << res*k%MOD*k%MOD << endl;


    return 0;
}