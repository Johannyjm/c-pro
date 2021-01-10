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

    dsu uf(440000);
    vector<int> edge_num(440000, 0);
    rep(i, n){
        int a, b;
        cin >> a >> b;
        --a;
        --b;

        uf.merge(a, b);
        ++edge_num[a];
        ++edge_num[b];
    }

    int res = 0;
    for(auto g: uf.groups()){
        int e = 0;
        for(auto v: g) e += edge_num[v];
        e /= 2;

        if(e == g.size() - 1) res += g.size() - 1;
        else res += g.size();
    }

    cout << res << endl;

    return 0;
}