#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    map<int, map<int, int>> mp;
    rep(i, n){
        mp[b[i]] = {i, a[i]};
    }

    rep(i, n){
        for(auto itr = mp.begin(); itr != mp.end(); ++itr){
            cout << itr->first << " " << itr->second->first << " " << itr->second->second << endl;
        }
    }

    return 0;
}