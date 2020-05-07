#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, a, b, c;
    cin >> n >> a >> b >> c;
    
    vector<int> l(n);
    rep(i, n) cin >> l[i];

    vector<vector<int>> dp(n, vector<int>(10000, 0));
    rep(j, n){
        for(int i = l[j]+1; i < 10000; ++i) dp[j][i] = i-l[j];
        for(int i = l[j]-1; i >= 0; --i) dp[j][i] = l[j]-i;
    }

    rep(i, n){
        rep(j, 111) cout << dp[i][j] << " ";
        cout << endl;
    }

    return 0;
}