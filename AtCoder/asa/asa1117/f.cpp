#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

ll ddp(string s){
    int n = s.size();

    ll dp[n+1][2][2] = {};
    dp[0][0][0] = 1;
    rep(i, n){
        int D = s[i] - '0';
        rep(j, 2){
            rep(k, 2){
                for(int d = 0; d <= (j? 9: D); ++d){
                    dp[i+1][j||(d<D)][k||(d==4||d==9)] += dp[i][j][k];
                }
            }
        }
    }

    return dp[n][0][1] + dp[n][1][1];
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll a, b;
    cin >> a >> b;
    --a;

    string as = to_string(a);
    string bs = to_string(b);

    cout << ddp(bs) - ddp(as) << endl;    

    return 0;
}