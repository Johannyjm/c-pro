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

    int n, q;
    cin >> n >> q;
    vector<int> c(n);
    vector<unordered_map<int, int>> cnt(n);
    rep(i, n){
        cin >> c[i];
        ++cnt[i][c[i]];
    }

    dsu uf(n);

    rep(_, q){
        int cmd, a, b;
        cin >> cmd >> a >> b;
        --a;
        --b;

        if(cmd == 1){
            if(uf.same(a, b)) continue;
            int pa = uf.leader(a);
            int pb = uf.leader(b);

            uf.merge(a, b);

            if(uf.leader(a) != pa){
                for(auto k: cnt[pa]){
                    cnt[uf.leader(b)][k.first] += k.second;
                    cnt[pa][k.first] = 0;
                }
            }
            else{
                for(auto k: cnt[pb]){
                    cnt[uf.leader(a)][k.first] += k.second;
                    cnt[pb][k.first] = 0;
                }
            }
        }

        if(cmd == 2){
            cout << cnt[uf.leader(a)][b+1] << "\n";
        }

        // rep(i, n) cout << uf.leader(i) << " ";
        // cout << endl;
        // rep(i, n){
        //     for(auto k: cnt[i]){
        //         cout << k.first << ":" << k.second << ", ";
        //     }
        //     cout << endl;
        // }
    }    

    return 0;
}