#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
const int MOD = 1000000007;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<ll> right_smaller(n);
    rep(i, n-1){
        ll cnt = 0;
        for(int j = i+1; j<n; ++j){
            if(a[i]>a[j]) ++cnt;
        }
        right_smaller[i] = cnt;
    }

    vector<ll> all_smaller(n);
    rep(i, n){
        ll cnt = 0;
        rep(j, n){
            if(a[i]>a[j]) ++cnt;
        }
        all_smaller[i] = cnt;
    }

    ll res = 0;
    const ll K_SUM = (k*(k-1)/2)%MOD;
    rep(i, n){
        if(all_smaller[i]==0) continue;
        res = ((res + (right_smaller[i]%MOD * k%MOD) % MOD) % MOD + (all_smaller[i]%MOD) * K_SUM % MOD) % MOD;
    }

    cout << res << endl;


    return 0;
}