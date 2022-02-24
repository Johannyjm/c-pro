#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, x;
    cin >> n >> x;

    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    vector<vector<bool>> dp(n, vector<bool>(11000, false));
    dp[0][a[0]] = true;
    dp[0][b[0]] = true;

    rep1(i, n){
        vector<bool> tmp(11000, false);
        rep(j, 11000){
            if(!dp[i-1][j]) continue;
            tmp[j+a[i]] = true;
            tmp[j+b[i]] = true;
        }

        dp[i] = tmp;
    }


    if(dp[n-1][x]) puts("Yes");
    else puts("No");

    return 0;
}