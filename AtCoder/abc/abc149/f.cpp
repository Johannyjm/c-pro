#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

vector<vector<ll>> g;
int cnt;
void dfs(int v, vector<bool> seen){

    seen[v] = true;
    ++cnt;
    for(auto nv: g[v]){
        if(seen[nv]) continue;

        dfs(nv, seen);
    }
}

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

ll mod_fac(ll n){
    ll ret = 1;
    for(ll i = 1; i <= n; ++i){
        ret = (ret*i) % MOD;
    }
    return ret;
}

ll mod_comb(ll n, ll k){
    ll numerator = 1;
    for(ll i = 0; i < k; ++i){
        numerator = numerator*(n-i) % MOD;
    }
    ll denominator = mod_fac(k);
    return mod_div(numerator, denominator);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    g.resize(n);
    vector<ll> a(n), b(n);
    rep(i, n-1){
        cin >> a[i] >> b[i];
        --a[i];
        --b[i];

        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }

    vector<ll> x(n-1);
    rep(i, n-1){
        int s = a[i];
        vector<bool> seen(n, false);
        seen[s] = true;
        seen[b[i]] = true;

        cnt = 0;
        dfs(s, seen);

        x[i] = min(cnt, n-cnt);
    }

    ll res = 0;
    rep(i, n-1){
        ll p = mod_mul(mod_sub(1, mod_pow(mod_div(1, 2), x[i])), mod_sub(1, mod_pow(mod_div(1, 2), n-x[i])));
        res = mod_add(res, p);
    }

    cout << res << endl;

    return 0;
}