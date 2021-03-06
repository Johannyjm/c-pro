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

    vector<int> x(m), y(m), z(m);
    rep(i, m){
        cin >> x[i] >> y[i] >> z[i];
        --x[i];
        --y[i];
    }

    dsu uf(n);
    rep(i, m){
        uf.merge(x[i], y[i]);
    }

    cout << uf.groups().size() << endl;

    return 0;
}