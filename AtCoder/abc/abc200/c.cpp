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
    vector<ll> a(n);
    map<ll, ll> mp;
    ll mxa = 0;
    vector<vector<ll>> cnt(200);
    rep(i, n){
        cin >> a[i];
        ++mp[a[i]];
        mxa = max(mxa, a[i]);
        cnt[]
    }

    ll res = 0;
    for(auto k: mp) res += k.second * (k.second - 1) / 2;

    for(auto k: mp){
        ll from = k.first;
        for(ll i = 1; i < mxa / 200 + 1; ++i){
            ll to = k.first + 200 * i;
            cout << from << " " << to << endl;
            res += mp[from] * mp[to];
        }
    }

    cout << res << endl;

    return 0;
}