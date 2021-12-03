#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int dp[330][330][330];

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, x, y;
    cin >> n >> x >> y;

    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    const int INF = 1001001001;
    rep(i, n) rep(j, n) rep(k, n){
        dp[i][j][k] = INF;
    }

    rep(j, a[0]+1) rep(k, b[0]+1){
        dp[0][j][k] = 1;
    }

    rep1(i, n){

        rep(j, n)
    }
    

    return 0;
}