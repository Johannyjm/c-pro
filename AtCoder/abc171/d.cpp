#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> a(n);

    map<ll, ll> mp;
    rep(i, n){
        cin >> a[i];
        ++mp[a[i]];
    }

    ll sm = 0;
    for(auto itr = mp.begin(); itr != mp.end(); ++itr){
        sm += itr->first * itr->second;
    }

    int q;
    cin >> q;

    rep(_, q){
        ll b, c;
        cin >> b >> c;

        sm -= b*mp[b];
        sm += c*mp[b];

        mp[c] += mp[b];
        mp[b] = 0;

        cout << sm << "\n";
    }



    return 0;
}