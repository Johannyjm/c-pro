#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int n;
vector<vector<ll>> a, dp;
ll rec(ll s, ll v){
    if(dp[s][v] != -1) return dp[s][v];
    

}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    a.resize(2*n, vector<ll>(2*n, -1));
    rep(i, 2*n-1){
        for(int j = i+1; j < 2*n; ++j) cin >> a[i][j];
    }

    // rep(i, 2*n){
        // rep(j, 2*n) cout << a[i][j] << " ";
        // cout << endl;
    // }

    dp.resize((1<<(2*n)), vector<ll>(2*n, -1));
    cout << rec(0, 0) << endl;

    return 0;
}