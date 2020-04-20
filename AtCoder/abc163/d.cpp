#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    COMinit();

    ll n, k;
    cin >> n >> k;

    const ll mod = 1000000007;

    vector<ll> sm(n+1, 0);
    sm[0] = 0;
    for(ll i = 1; i < n+1; ++i) sm[i] = (sm[i-1]+i)%mod;

    vector<ll> sm_t(n+1, 0);
    sm_t[n] = n;
    for(ll i = 1; i < n+1; ++i) sm_t[n-i] = (sm_t[n-i+1]+(n-i))%mod;

    // rep(i, n+1) cout << sm[i] << " ";
    // cout << endl;

    // rep(i, n+1) cout << sm_t[i] << " ";
    // cout << endl;

    ll res = 0;
    for(ll i = k; i <= n+1; ++i){
        // cout << sm_t[n-i+1] << " " << sm[i-1] << endl;
        res =  (res + (sm_t[n-i+1]+mod - sm[i-1] + 1) % mod) % mod;
        
    }

    cout << res << endl;

    return 0;
}