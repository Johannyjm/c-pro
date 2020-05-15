#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int n;
vector<int> w;
vector<vector<int>> dp;

int solve(int l, int r){
    if((r-l) <= 1) return 0;
    if((r-l) == 2){
        if(abs(w[l] - w[l+1]) <= 1) return 2;
        else return 0;
    }
    if(dp[l][r] != -1) return dp[l][r];

    if(abs(w[l] - w[r-1]) <= 1 && solve(l+1, r-1) == r-l-2) dp[l][r] = max(dp[l][r], r-l);
    for(int i = l+1; i < r; ++i) dp[l][r] = max(dp[l][r], solve(l, i)+solve(i, r));

    return dp[l][r];
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    while(1){
        cin >> n;
        if(n == 0) break;

        w.resize(n);
        rep(i, n) cin >> w[i];

        dp.assign(n+2, vector<int>(n+2, -1));

        cout << solve(0, n) << endl;
    }

    return 0;
}