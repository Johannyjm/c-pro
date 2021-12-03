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

    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    dsu uf(n);
    rep(i, n) for(int j = i+1; j < n; ++j) for(int k = j+1; k < n; ++k){

        if((b[j]-b[i]) * (a[k]-a[i]) == (b[k]-b[i]) * (a[j]-a[i])){
            if(uf.same(i, j)) continue;
            else uf.merge(i, j);
            if(uf.same(i, k)) continue;
            else uf.merge(i, k);
        }
    }

    ll res = 0;
    unordered_set<int> seen;
    rep(i, n){
        if(seen.count(uf.leader(i))) continue;
        if(uf.size(i) == 1) res += n - 1;
        else res += (n - uf.size(i) + 1) * 2;

        seen.insert(uf.leader(i));
    }

    cout << res << endl;

    return 0;
}