#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;

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

    int n, m, k;
    cin >> n >> m >> k;

    mint res = 0;
    rep(i, k+1){
        res += mint(m) * comb(n-1, i) * mint(m-1).pow(n-1-i);
    }

    cout << res.val() << endl;


    return 0;
}