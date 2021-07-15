#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    ll res = 1;
    const ll mod = 1000000007;

    vector<ll> c(n);
    rep(i, n) cin >> c[i];

    sort(c.begin(), c.end());

    rep(i, n){
        res = res * max(0ll, (c[i]-i)) % mod;
    }

    cout << res << endl;

    return 0;
}