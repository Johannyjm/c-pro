#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, Q;
    cin >> n >> m >> Q;
    vector<vector<int>> cnt(n, vector<int>(n, 0));
    rep(i, m){
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        ++cnt[l][r];
    }

    rep(i, n) rep1(j, n) cnt[i][j] += cnt[i][j-1];
    rep1(j, n) rep1(i, n) cnt[n-i-1][j] += cnt[n-i][j];

    rep(i, Q){
        int p, q;
        cin >> p >> q;
        --p;
        --q;

        cout << cnt[p][q] << "\n";
    }


    return 0;
}