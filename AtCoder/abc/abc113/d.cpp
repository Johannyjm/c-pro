#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll h, w, k;
    cin >> h >> w >> k;
    
    mint dp[110][10] = {};
    dp[0][0] = 1;
    rep1(i, h){
        rep(j, w){
            mint nxt = dp[i-1][j];
            if(j > 0) nxt += dp[i-1][j-1];
            if(j < w-1) nxt += dp[i-1][j+1];
            dp[i][j] = nxt;
        }
    }
    rep(i, h){
        rep(j, w) cout << dp[i][j].val() << " ";
        cout << endl;
    }

    cout << dp[h-1][k-1].val() << endl;

    return 0;
}