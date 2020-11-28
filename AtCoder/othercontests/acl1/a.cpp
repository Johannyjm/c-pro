#include <bits/stdc++.h>
#include <atcoder/all>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> x(n), y(n);
    vector<pair<pair<int, int>, int>> points(n);
    rep(i, n){
        cin >> y[i] >> x[i];
        points[i] = {{y[i], x[i]}, i};
    }

    sort(points.begin(), points.end());

    dsu uf(n);
    map<int, int> mp;
    rep(i, n){
        int x = points[i].first.second;
        int idx = points[i].second;
        if(mp.size() == 1) mp[x] = idx;
        int mn = x;
        for(auto k: mp){
            if(k.first > x) break;
            uf.merge(idx, k.second);
            mn = min(mn, k.first);
        }
        mp[mn] = uf.leader(idx);
    }

    rep(i, n) cout << uf.size(i) << endl;
    
    return 0;
}