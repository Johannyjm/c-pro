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

    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> ab(n);
    rep(i, n){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        ab[i] = {{a, b}, i};
    }

    sort(ab.begin(), ab.end());

    dsu uf(n);
    map<int, int> mp;
    rep(i, n){
        int idx = ab[i].second;
        int y = ab[i].first.second;

        int mn = y;
        for(auto k: mp){
            if(k.first > y) break;
            uf.merge(idx, k.second);
            mn = min(mn, k.first);
        }

        mp[mn] = uf.leader(idx);
    }

    rep(i, n) cout << uf.size(i) << endl;

    return 0;
}