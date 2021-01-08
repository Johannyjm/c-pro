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

    const int maxn = 440000;
    init(maxn);

    ll n, k;
    cin >> n >> k;

    if(k >= n-1){
        cout << comb(n+n-1, n).val() << endl;
        return 0;
    }
    
    mint res = 1;
    for(int i = 1; i <= k; ++i){
        res += comb(n, i) * comb(n-1, i);
    }

    cout << res.val() << endl;

    return 0;
}