#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    bool dp[n][11000] = {};
    dp[0][0] = true;
    dp[0][a[0]] = true;

    rep(i, n-1){
        rep(j, 10100){
            if(dp[i][j]){
                dp[i+1][j] = true;
                if(j+a[i+1] <= 10000) dp[i+1][j+a[i+1]] = true;
            }
        }
    }

    if(dp[n-1][s]) puts("Yes");
    else puts("No");

    return 0;
}