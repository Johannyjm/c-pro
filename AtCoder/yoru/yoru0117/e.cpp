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

    vector<ll> sm(n+1, 0);
    rep(i, n) sm[i+1] = sm[i] + a[i];

    // for(auto e: sm) cout << e << " ";
    // cout << endl;

    unordered_map<ll, ll> cnt;
    for(auto e: sm){
        ++cnt[e % m];
    }

    ll res = 0;
    for(auto k: cnt){
        res += k.second*(k.second-1)/2;
    }

    cout << res << endl;

    return 0;
}