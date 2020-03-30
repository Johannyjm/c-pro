#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(60, 0));
    rep(i, n){
        ll num;
        cin >> num;
        ll d = 0;
        while(num){
            if(num%2) a[i][d] = 1;
            num /= 2;
            ++d;
        }
    }

    // rep(i, n) {
    //     rep(j, 60) cout << a[i][j];
    //     cout << endl;
    // }

    vector<ll> bit_num(60, 0);
    rep(i, n){
        rep(j, 60) bit_num[j] += a[i][j];
    }

    // cout << endl;
    // rep(i, 60) cout << bit_num[i];
    // cout << endl;

    ll MOD = 1000000007;
    ll res = 0;
    ll base = 1;
    rep(i, 60){
        res += base%MOD * bit_num[i]%MOD * (n - bit_num[i])%MOD;
        res %= MOD;

        base *= 2;
    }
    cout << res << endl;

    return 0;
}