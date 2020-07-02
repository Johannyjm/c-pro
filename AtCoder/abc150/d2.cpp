#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i, n){
        cin >> a[i];
        a[i] /= 2;
    }

    sort(a.begin(), a.end());
    vector<pair<ll, ll>> comp;
    comp.push_back(make_pair(a[0], 1));
    rep1(i, n){
        if(comp.back().first == a[i]) ++comp.back().second;
        else comp.push_back(make_pair(a[i], 1));
    }

    map<ll, ll> mp;
    rep(i, comp.size()-1){
        ll by = 1;
        ll val = comp[i].first;
        ll cnt = comp[i].second;
        while(val*by <= m){
            mp[val*by] += cnt;
            by += 2;
        }
    }

    ll by = 1;
    ll val = comp.back().first;
    ll cnt = comp.back().second;
    ll res = 0;
    while(val*by <= m){
        mp[val*by] += cnt;

        if(mp[val*by] == n) ++res;
        by += 2;
    }

    cout << res << endl;

    return 0;
}