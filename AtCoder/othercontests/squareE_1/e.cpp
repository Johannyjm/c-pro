#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

ll mod_add(ll a, ll b){
    return ((a % MOD) + (b % MOD)) % MOD;
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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, q;
    cin >> n >> q;

    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> c(q);
    rep(i, q){
        cin >> c[i];
        --c[i];
    }

    vector<ll> sm(n);
    sm[0] = 0;
    rep1(i, n){
        sm[i] = sm[i-1];
        sm[i] = mod_add(sm[i], mod_pow(a[i-1], a[i]));
    }

    ll res = 0;
    int from = 0;
    c.push_back(0);
    rep(i, q+1){
        int to = c[i];

        bool flipped = false;
        if(to < from){
            swap(from, to);
            flipped = true;
        }

        ll dist = (sm[to]+MOD - sm[from]) % MOD;
        res = mod_add(res, dist);
        
        if(flipped) swap(from, to);

        from = to;
    }

    cout << res << endl;



    return 0;
}