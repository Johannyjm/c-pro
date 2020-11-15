#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

vector<mint> fact, ifact, double_fact;
void init(int n) {
    fact.resize(n+1);
    ifact.resize(n+1);
    double_fact.resize(n+1);
    fact[0] = 1;

    for(int i = 1; i <= n; ++i) fact[i] = fact[i-1] * i;

    ifact[n] = fact[n].inv();
    for(int i = n; i >= 1; --i) ifact[i-1] = ifact[i] * i;

    double_fact[1] = 1;
    for(int i = 3; i <= n; i += 2) double_fact[i] = double_fact[i-2] * i;
}

mint comb(int n, int k){
    return fact[n] * ifact[k] * ifact[n-k];
}
mint perm(int n, int k){
    return fact[n] * ifact[n-k];
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    init(220000);

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end());

    vector<mint> sm(n, 0);
    sm[0] = a[0];
    rep1(i, n){
        sm[i] = sm[i-1] + a[i];
    }

    mint res = 0;
    for(int i = k-2; i < n-1; ++i){
        // cout << (sm[n-1]-sm[i]).val() << " " << sm[k-i+2].val() << endl;
        res += comb(i, k-2) * ((sm[n-1]-sm[i]) - (sm[n-i-2]));
    }

    cout << res.val() << endl;


    return 0;
}