#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

vector<int> row, col;
vector<vector<int>> dp;

int rec(int l, int r){
    cout << l << " " << r << endl;
    if(dp[l][r] != -1) return dp[l][r];
    if(r-l <= 1) return dp[l][r] = INF;
    if(r-l == 2) return dp[l][r] = row[l] * col[l] * col[r-1];

    int ret = INF;
    for(int i = l; i < r; ++i){
        ret = min(ret, rec(l, i) + rec(i+1, r));
    }
    cout << ret << endl;

    return dp[l][r] = ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    row.resize(n);
    col.resize(n);
    rep(i, n) cin >> row[i] >> col[i];

    dp.assign(n+1, vector<int>(n+1, -1));
    int res = rec(0, n);
    rep(i, n){
        rep(j, n) cout << dp[i][j] << " ";
        cout << endl;
    }
    cout << res << endl;

    return 0;
}