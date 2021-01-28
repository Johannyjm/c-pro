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
    vector<int> a(n), b(n), c(n), d(n);
    rep(i, n) cin >> a[i] >> b[i];
    rep(i, n) cin >> c[i] >> d[i];

    vector<vector<int>> g(n*2);
    rep(i, n){
        rep(j, n){
            if(a[i] < c[j] && b[i] < d[j]){
                g[i].push_back(j+n);
                g[j+n].push_back(i);
            }
        }
    }

    int res = 0;
    vector<bool> used(2*n, false);

    while(1){
        int min_size = n;
        vector<pair<int, int>> min_pairs;
        rep(i, 2*n){
            int s = 0;
            for(auto nv: g[i]){
                if(!used[nv]) ++s;
            }
            if(s != 0) min_size = min(min_size, s);
        }

        rep(i, 2*n){
            int s = 0;
            int p = -1;
            for(auto nv: g[i]){
                if(!used[nv]){
                    ++s;
                    p = nv;
                }
            }
            if(s == 0) continue;
            if(s == min_size){
                if(!used[i] && !used[p]) min_pairs.push_back({i, p});
            }
        }

        if(min_pairs.size() == 0) break;

        for(auto p: min_pairs){
            if(used[p.first] || used[p.second]) continue;
            ++res;
            used[p.first] = true;
            used[p.second] = true;
        }
    }

    cout << res << endl;

    return 0;
}