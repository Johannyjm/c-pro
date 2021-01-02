#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

ll n, k;
vector<ll> a, f;
bool check(ll tl){
    ll need = 0;
    rep(i, n){
        if(a[i] * f[i] > tl){
            need += a[i] - (tl / f[i]);
        }
    }

    return need <= k;
}


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    a.resize(n);
    f.resize(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> f[i];

    sort(a.begin(), a.end());
    sort(f.begin(), f.end(), greater<ll>());

    // rep(i, n) cout << a[i] << " ";
    // cout << endl;
    // rep(i, n) cout << f[i] << " ";
    // cout << endl;

    ll ok = 1100000000000;
    ll ng = -1;
    while(ok-ng > 1){
        ll mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;

    return 0;
}