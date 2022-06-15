#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int r, c;
    cin >> r >> c;
    --r;
    --c;
    vector<vector<int>> a(2, vector<int>(2));
    rep(i, 2) rep(j, 2) cin >> a[i][j];

    cout << a[r][c] << endl;

    return 0;
}