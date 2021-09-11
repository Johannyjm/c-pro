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

    ll l, q;
    cin >> l >> q;
    vector<ll> c(q), x(q);
    vector<ll> cuts;

    cuts.push_back(0);
    cuts.push_back(l);
    rep(i, q){
        cin >> c[i] >> x[i];
        if(c[i] == 1) cuts.push_back(x[i]);
    }

    sort(cuts.begin(), cuts.end());

    for(auto e: cuts) cout << e << " ";
    cout << endl;

    vector<ll> logs;
    rep(i, (int)cuts.size()-1){
        logs.push_back(cuts[i+1]-cuts[i]);
    }

    for(auto e: logs) cout << e << " ";
    cout << endl;

    unordered_map<ll, int> cnv;
    rep(i, (int)cuts.size()){
        cnv[cuts[i]] = i;
    }

    fenwick_tree<ll> bit((int)cuts.size());
    bit.add((int)cuts.size(), l);

    rep(i, q){
        if(c[i] == 1){
            bit.add(cnv[x[i]], x[i]);
        }
        if(c[i] == 2){
            
        }
    }

    return 0;
}