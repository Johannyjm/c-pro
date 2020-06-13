#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, q;
    cin >> n >> m >> q;

    vector<int> l(m), r(m);
    rep(i, m){
        cin >> l[i] >> r[i];
        --l[i];
        --r[i];
    }

    vector<vector<int>> sm(n, vector<int>(n, 0));
    rep(i, m){
        for(int j = r[i]; j < n; ++j) ++sm[l[i]][j];
    }

    rep1(i, n) rep(j, n) sm[n-i-1][j] += sm[n-i][j];
    
    rep(_, q){
        int a, b;
        cin >> a >> b;
        --a;
        --b;

        cout << sm[a][b] << "\n";
    }

    return 0;
}