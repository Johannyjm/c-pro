#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll mod_add(ll a, ll b){
    return ((a % MOD) + (b % MOD)) % MOD;
}

ll mod_sub(ll a, ll b){
    return ((a + MOD) - b) % MOD;
}
 
ll mod_mul(ll a, ll b){
    return ((a % MOD) * (b % MOD)) % MOD;
}

ll mod_pow(ll x, ll r){
    if (r == 0) return 1;

    else if (r == 1) return x % MOD;

    else if (r % 2 == 0){
        ll t = mod_pow(x, r/2) % MOD;
        return mod_mul(t, t);
    }

    else{
        ll t = mod_pow(x, r/2) % MOD;
        ll k = mod_mul(t, t);
        return ((k % MOD) * (x % MOD)) % MOD;
    }
}

ll mod_div(ll a, ll b){
    return mod_mul(a, mod_pow(b, MOD - 2));
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<ll>> bit(n, vector<ll>(66, 0));
    rep(i, n){
        ll num = a[i];
        int base = 0;
        while(num){
            bit[i][base] = num%2;
            num /= 2;
            ++base;
        }
    }

    // rep(i, n){
    //     rep(j, 66) cout << bit[i][j] << " ";
    //     cout << endl;
    // }

    ll res = 0;
    ll base = 0;
    rep(i, 66){
        ll sm = 0;
        rep(j, n){
            sm += bit[j][i];
        }
        ll m = sm*(n-sm) % MOD;
        res = (res+mod_mul(m, mod_pow(2, base))) % MOD;
        ++base;
    }

    cout << res << endl;


    return 0;
}