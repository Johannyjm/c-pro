#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

bool legal(int i, int j, int k, int l){
    if(i==0&&j==1&&k==2) return false;
    if(j==0&&k==1&&l==2) return false;
    if(i==0&&j==2&&k==1) return false;
    if(j==0&&k==2&&l==1) return false;
    if(i==1&&j==0&&k==2) return false;
    if(j==1&&k==0&&l==2) return false;
    if(i==0&&j==1&&l==2) return false;
    if(i==0&&k==1&&l==2) return false;

    return true;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    mint dp[110][4][4][4] = {};
    rep(i, 4) rep(j, 4) rep(k, 4){
        if(i==0&&j==1&&k==2) continue;
        if(i==0&&j==2&&k==1) continue;
        if(i==1&&j==0&&k==2) continue;

        dp[3][i][j][k] = 1;
    }

    for(int d = 3; d <= n; ++d){
        rep(i, 4) rep(j, 4) rep(k, 4){

            rep(l, 4){
                if(legal(i, j, k, l)) dp[d+1][j][k][l] += dp[d][i][j][k];
            }
        }
    }

    mint res = 0;
    rep(i, 4) rep(j, 4) rep(k, 4) res += dp[n][i][j][k];

    cout << res.val() << endl;


    return 0;
}