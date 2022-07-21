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

    dsu uf(n);
    vector<unordered_set<int>> g(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].insert(b);
        g[b].insert(a);
        uf.merge(a, b);
    }

    rep(v, n){
        if(g[v].size() > 2){
            puts("No");
            return 0;
        }
    }

    for(auto group: uf.groups()){
        if(group.size() == 1) continue;
        int d1 = 0;

        for(auto v: group){
            if(g[v].size() == 1) ++d1;
        }

        if(d1 != 2){
            puts("No");
            return 0;
        }
    }

    puts("Yes");

    return 0;
}