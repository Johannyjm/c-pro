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

    vector<vector<int>> g(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;

        --a;
        --b;
        g[min(a, b)].push_back(max(a, b));
    }

    vector<int> res = {0};
    dsu uf(n);
    int now = n;
    for(int v = n-1; v > 0; --v){

        for(auto nv: g[v]){
            if(uf.same(v, nv)) continue;
            uf.merge(v, nv);
            --now;
        }

        res.push_back(now - v);
    }

    reverse(res.begin(), res.end());

    for(auto e: res) cout << e << " ";
    cout << endl;


    return 0;
}