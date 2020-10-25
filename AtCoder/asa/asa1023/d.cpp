#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    map<ll, ll> mp;
    rep(i, n){
        ++mp[a[i] + i];
    }

    ll res = 0;
    rep(i, n){
        res += mp[i-a[i]];
    }

    cout << res << endl;

    return 0;
}