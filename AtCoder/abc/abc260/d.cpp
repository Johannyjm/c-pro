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

    int n, k;
    cin >> n >> k;

    vector<int> p(n);
    rep(i, n){
        cin >> p[i];
        --p[i];
    }

    dsu uf(n);
    set<int> st;

    vector<int> res(n, -1);

    rep(i, n){
        auto iter = st.upper_bound(p[i]);

        if(iter == st.end()){
            st.insert(p[i]);
        }
        else{
            int val = *iter;
            st.erase(val);
            st.insert(p[i]);

            uf.merge(p[i], val);
        }

        if(uf.size(p[i]) == k){
            // cout << "del: " << p[i] << " " << uf.leader(p[i]) << endl;
            res[uf.leader(p[i])] = i+1;
            // res[p[i]] = i+1;
            // res[p[i]] = i+1;
            st.erase(p[i]);
        }

        // cout << i << " " << p[i] << endl;

        // for(auto e: st) cout << e << " ";
        // cout << endl;
        // for(auto e: res) cout << e << " ";
        // cout << endl;
        // cout << endl;
    }

    rep(i, n){
        // cout << i << " " << uf.leader(i) << endl;
        if(res[i] == -1){
            cout << res[uf.leader(i)] << "\n";
        }
        else{
            cout << res[i] << "\n";
        }
    }


    // for(auto g: uf.groups()){
    //     for(auto e: g) cout << e << " ";
    //     cout << endl;
    // }

    return 0;
}