#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    ll k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end(), greater<ll>());

    rep(i, n){
        ll num = min(k, a[i] / x);
        a[i] -= num * x;
        k -= num;
    }

    sort(a.begin(), a.end(), greater<ll>());
    if(k >= n){
        cout << 0 << endl;
        return 0;
    }
    
    rep(i, k){
        a[i] = 0;
    }

    ll res = 0;
    for(auto elem: a) res += elem;

    cout << res << endl;

    return 0;
}