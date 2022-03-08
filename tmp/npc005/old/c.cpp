#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

template<typename T>
vector<T> compress(vector<T> &a){
    vector<T> ret = a;
    sort(ret.begin(), ret.end());
    ret.erase(unique(ret.begin(), ret.end()), ret.end());
    for(int i = 0; i < (int)a.size(); ++i){
        a[i] = lower_bound(ret.begin(), ret.end(), a[i]) - ret.begin();
    }
    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<int> aq(n+q);
    rep(i, n+q) cin >> aq[i];

    vector<int> cnv = compress(aq);

    vector<int> a, Q;
    rep(i, n+q){
        if(i < n) a.push_back(aq[i]);
        else Q.push_back(aq[i]);
    }

    // for(auto e: a) cout << e << " ";
    // cout << endl;
    // for(auto e: Q) cout << e << " ";
    // cout << endl;

    fenwick_tree<int> bit(220000);
    for(auto e: a){
        bit.add(e, 1);
    }

    for(auto x: Q){
        cout << bit.sum(x, 220000) << "\n";
    }



    return 0;
}