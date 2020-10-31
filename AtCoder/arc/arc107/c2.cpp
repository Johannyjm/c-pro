#include <bits/stdc++.h>
#include <atcoder/all>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
typedef long long ll;
using mint = modint998244353;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> a(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> a[i][j];

    dsu ufi(n), ufj(n);

    rep(x, n) rep(y, n){
        if(x <= y) continue;

        // for row
        bool r_swappable = true;
        bool c_swappable = true;
        rep(i, n){
            if(a[i][x] + a[i][y] > k){
                r_swappable = false;
            }

            if(a[x][i] + a[y][i] > k){
                c_swappable = false;
            }
        }

        if(r_swappable) ufi.merge(x, y);
        if(c_swappable) ufj.merge(x, y);

    }

    mint smi = 1;
    mint smj = 1;
    for(auto e: ufi.groups()){
        mint s = e.size();
        mint fac = 1;
        for(mint i = 1; i.val() <= s.val(); ++i) fac *= i;

        smi *= fac;
    }

    for(auto e: ufj.groups()){
        mint s = e.size();
        mint fac = 1;
        for(mint i = 1; i.val() <= s.val(); ++i) fac *= i;

        smj *= fac;
    }

    // cout << smi.val() << " " << smj.val() << endl;
    cout << (smi*smj).val() << endl;


    return 0;
}