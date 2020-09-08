#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int r, c, d;
    cin >> r >> c >> d;

    vector<vector<int>> a(r, vector<int>(c));
    rep(i, r) rep(j, c) cin >> a[i][j];

    int res = -1;
    rep(i, r) rep(j, c){
        if(d%2==0 && (i+j)%2==1) continue;
        if(d%2==1 && (i+j)%2==0) continue;
        if(d < i+j) continue;
        res = max(res, a[i][j]);
    }

    cout << res << endl;

    return 0;
}