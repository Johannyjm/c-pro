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

    // vector<vector<int>> g(n);
    vector<set<int>> g(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;

        --a;
        --b;
        g[a].insert(-b);
        g[b].insert(-a);
    }

    // rep(i, n){
    //     sort(g[i].begin(), g[i].end(), greater<int>());
    // }
    vector<int> res = {0};
    dsu uf(n);
    for(int v = n-1; v > 0; --v){

        for(auto nv: g[v]){
            if(-nv < v) break;
            if(uf.same(v, -nv)) continue;
            uf.merge(v, -nv);
        }

        res.push_back(uf.groups().size() - v);
    }

    reverse(res.begin(), res.end());

    for(auto e: res) cout << e << " ";
    cout << endl;


    return 0;
}