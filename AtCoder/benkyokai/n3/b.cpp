#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll bias = k * (k-1) / 2;
    bias %= 1000000007;

    ll res = 0;
    rep(i, n){
        ll cnt1 = 0;
        ll cnt2 = 0;
        rep(j, i){
            if(a[j] > a[i]) ++cnt1;
        }
        rep(j, n){
            if(a[j] > a[i]) ++cnt2;
        }

        res += cnt1*k + cnt2*bias;
        res %= 1000000007;
    }

    cout << res << endl;

    return 0;
}