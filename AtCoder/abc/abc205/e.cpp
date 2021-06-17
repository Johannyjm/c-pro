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

    init(2200000);

    int n, m, k;
    cin >> n >> m >> k;

    mint res = comb(n+m, min(n, m));
    // cout << res.val() << endl;

    if(m == 0){
        if(k >= n) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }

    mint sub = 0;
    for(ll b = 0; b < m; ++b){
        ll w = b + k + 1;
        ll other = n+m - b - w;
        // cout << endl;
        // cout << b << " " << w << " " << other << endl;
        if(w > n || b > m || other < 0) break;

        ll nr = n - w;
        ll mr = m - b;

        sub += comb(b*2, b) * comb(nr+mr, min(nr, mr));

        // cout << b << " " << w << " " << comb(b*2, b).val() << " " << comb(nr+mr, nr).val() << " " << sub.val() << endl;

        // res -= sub;
    }

    res -= sub;

    cout << res.val() << endl;

    return 0;
}