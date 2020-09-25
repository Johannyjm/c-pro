#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

ll dp[110][2][110];

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();
    int K;
    cin >> K;

    dp[0][0][0] = 1;
    rep(i, n){
        int D = s[i] - '0';
        rep(j, 2){
            rep(k, n){
                rep(d, (j? 10: D+1)){
                    dp[i+1][j||d<D][k+(d!=0)] += dp[i][j][k];
                }
            }
        }
    }

    cout << dp[n][0][K] + dp[n][1][K] << endl;


    return 0;
}