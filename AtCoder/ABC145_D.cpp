#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll facc(ll k){
    ll sum = 1;
    ll MOD = 1e9 + 7;
    for (ll i = 1; i <= k; ++i) {
        sum = (sum * i) % MOD;
    }
    return sum;
}

ll calc(ll a, ll b, ll p) {
    if (b == 0) {
        return 1;
    } else if (b % 2 == 0) {
        ll d = calc(a, b / 2, p);
        return (d * d) % p;
    } else {
        return (a * calc(a, b - 1, p)) % p;
    }
}

const int MAX = 5100000;
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
    ll X, Y;
    cin >> X >> Y;
    ll a = min(X, Y);
    ll b = max(X, Y);
    ll MOD = 1e9 + 7;

    for (ll i = 0; i < min(X, Y); ++i){
        if(b == 2 * a) break;
        if(b > 2 * a){
            cout << 0 << endl;
            return 0;
        } else{
            b++;
            a--;
        }
    }
    // cout << a << " " << b << endl;
    ll up = facc(b / 2);
    ll down = (facc(b - X) * facc(b / 2 - b + X)) % MOD;

    COMinit();
    cout << COM(b / 2, b - X) << endl;


    




}