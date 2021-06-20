#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    unordered_map<ll, ll> cnt;
    ll res = 0;
    ++cnt[a[0]];
    rep1(i, n){
        res += i;
        res -= cnt[a[i]];
        ++cnt[a[i]];
    }

    cout << res << endl;

    return 0;
}