#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<ll> s(n, 0);
    s[0] = a[0];
    map<ll, ll> mp;
    ++mp[0];
    ++mp[s[0]];
    rep1(i, n){
        s[i] = s[i-1] + a[i];
        ++mp[s[i]];
    }

    ll res = 0;
    for(auto itr = mp.begin(); itr != mp.end(); ++itr){
        if(itr->second > 1) res += itr->second * (itr->second - 1) / 2; 
    }

    cout << res << endl;


    return 0;
}