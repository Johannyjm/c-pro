#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

const ll MOD = 998244353;

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

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<ll> cnt(n, 0);
    rep(i, n){
        ll d;
        cin >> d;
        if(i==0 && d!=0){
            cout << 0 << endl;
            return 0;
        }
        ++cnt[d];
    }

    if(cnt[0] != 1){
        cout << 0 << endl;
        return 0;
    }

    ll res = 1;
    bool isend = false;
    for(int i = 1; i < n; ++i){
        if(cnt[i] == 0) isend = true;
        if(isend && cnt[i]!=0){
            cout << 0 << endl;
            return 0;
        }
        if(!isend) res = mod_mul(res, mod_pow(cnt[i-1], cnt[i]));
    }

    cout << res << endl;

    return 0;
}