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
    vector<ll> a(n), b(n);
    ll sma = 0;
    ll smb = 0;
    rep(i, n){
        cin >> a[i];
        sma += a[i];
    }
    rep(i, n){
        cin >> b[i];
        smb += b[i];
    }

    vector<vector<int>> g(n);
    dsu uf(n);
    rep(i, m){
        int c, d;
        cin >> c >> d;
        --c;
        --d;

        g[c].push_back(d);
        g[d].push_back(c);

        if(!uf.same(c, d)) uf.merge(c, d);
    }

    // cout << sma << " " << smb << endl;

    if(uf.groups().size() == 1){
        if(sma == smb) puts("Yes");
        else puts("No");
        return 0;
    }

    for(auto group: uf.groups()){
        ll sm1 = 0;
        ll sm2 = 0;
        for(auto v: group){
            sm1 += a[v];
            sm2 += b[v];
        }
        if(sm1 != sm2){
            puts("No");
            return 0;
        }
    }
    puts("Yes");

    return 0;
}