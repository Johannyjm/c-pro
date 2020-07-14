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
    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    map<pair<int, int>, int> mp;
    rep(i, n) rep(j, n){
        if(i == j) continue;
        ++mp[make_pair(x[j]-x[i], y[j]-y[i])];
    }

    int sub = 0;
    for(auto itr = mp.begin(); itr != mp.end(); ++itr){
        sub = max(sub, itr->second);
    }

    cout << n-sub << endl;

    return 0;
}