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
    rep(i, m){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        uf.merge(a, b);
    }

    int mx = 0;
    for(auto group: uf.groups()){
        mx = max((int)group.size(), mx);
    }

    cout << mx << endl;

    return 0;
}