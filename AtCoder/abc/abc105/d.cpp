#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<ll> sm(n, 0);
    sm[0] = a[0];
    rep1(i, n){
        sm[i] = sm[i-1] + a[i];
    }

    // rep(i, n) cout << sm[i] << " ";
    // cout << endl;

    unordered_map<ll, ll> mods;
    rep(i, n){
        ++mods[sm[i] % m];
    }

    ll res = 0;
    for(auto k: mods){
        if(k.first == 0){
            res += k.second;
            res += k.second*(k.second-1)/2;
        }
        else res += k.second*(k.second-1)/2;
    }

    cout << res << endl;

    return 0;
}