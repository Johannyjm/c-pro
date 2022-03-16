#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    vector<ll> s(n+1, 0);
    for(int i = 1; i < n+1; ++i){
        s[i] = s[i-1] + a[i-1];
    }

    // for(auto e: s) cout << e << " ";
    // cout << endl;

    unordered_map<ll, ll> cnt;
    ll res = 0;
    for(auto e: s){
        res += cnt[e-k];
        ++cnt[e];
    }

    cout << res << endl;
    


    return 0;
}
