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

    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    vector<ll> c(m);
    vector<pair<ll, int>> abc(m);
    vector<vector<int>> g(n);
    rep(i, m){
        cin >> a[i] >> b[i] >> c[i];
        // g[a].push_back(b);
        // g[b].push_back(a);
        abc[i] = {c[i], i};
    }

    sort(abc.begin(), abc.end());

    dsu uf(n);
    ll res = 0;
    rep(i, m){
        int idx = abc[i].second;
        if(abc[i].first >= 0 && uf.same(a[idx]-1, b[idx]-1)){
            res += c[idx];
        }
        else{
            uf.merge(a[idx]-1, b[idx]-1);
        }
    }

    cout << res << endl;

    return 0;
}