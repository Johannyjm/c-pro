#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

ll fact(ll num){
    ll ret = 1;
    const ll MOD = 1000000007;
    rep1(i, num+1) ret = ((ret%MOD) * i) % MOD;
    
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    
    if(abs(n-m) > 1){
        cout << 0 << endl;
        return 0;
    }

    const ll MOD = 1000000007;
    ll res = (fact(n) * fact(m)) % MOD;

    if(n==m) res = res * 2 % MOD;
    cout << res << endl;

    return 0;
}