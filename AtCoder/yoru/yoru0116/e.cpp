#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

double dp[110][110][110];

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;

    dp[a][b][c] = 1.0;
    for(int i = a; i < 100; ++i){
        for(int j = b; j < 100; ++j){
            for(int k = c; k < 100; ++k){
                dp[i+1][j][k] += dp[i][j][k] * (double(i) / double(i+j+k));
                dp[i][j+1][k] += dp[i][j][k] * (double(j) / double(i+j+k));
                dp[i][j][k+1] += dp[i][j][k] * (double(k) / double(i+j+k));
            }
        }
    }

    double res = 0.0;
    rep(i, 100) rep(j, 100){
        res += dp[100][i][j] * (100-a + max(0, i-b) + max(0, j-c));
        res += dp[i][100][j] * (max(0, i-a) + 100-b + max(0, j-c));
        res += dp[i][j][100] * (max(0, i-a) + max(0, j-b) + 100-c);
    }

    cout << setprecision(20);
    cout << res << endl;

    return 0;
}