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
    
    dp[a][b][c] = 1;
    for(int i = a; i <= 100; ++i){
        for(int j = b; j <= 100; ++j){
            for(int k = c; k <= 100; ++k){
                if(i==100 || j==100 || k==100) continue;

                dp[i+1][j][k] += dp[i][j][k] * i/(i+j+k);
                dp[i][j+1][k] += dp[i][j][k] * j/(i+j+k);
                dp[i][j][k+1] += dp[i][j][k] * k/(i+j+k);
            }
        }
    }

    double res = 0;
    rep(j, 100) rep(k, 100){
        // if(dp[100][j][k]!=0) cout << j << " " << k << " " << ((100-a)+(j-b)+(k-c)) << " " << dp[100][j][k] << endl;
        res += ((100-a)+(j-b)+(k-c)) * dp[100][j][k];
    }
    // cout << endl;
    rep(i, 100) rep(k, 100){
        // if(dp[i][100][k]!=0) cout << i << " " << k << " " <<((i-a)+(100-b)+(k-c)) << " " << dp[i][100][k] << endl;
        res += ((i-a)+(100-b)+(k-c)) * dp[i][100][k];
    }
    // cout << endl;
    rep(i, 100) rep(j, 100){
        // if(dp[i][j][100]!=0) cout << i << " " << j << " " <<((i-a)+(j-b)+(100-c)) << " " << dp[i][j][100] << endl;
        res += ((i-a)+(j-b)+(100-c)) * dp[i][j][100];
    }

    cout << setprecision(20);
    cout << res << endl;

    // cout << dp[99][99][99] << endl;
    // cout << dp[100][99][99] << endl;
    // cout << dp[99][100][99] << endl;

    // printf("%.19f\n", res);

    // for(int i = a; i <= 100; ++i){
    //     for(int j = b; j <= 100; ++j){
    //         for(int k = c; k <= 100; ++k){
    //             cout << dp[i][j][k] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }


    return 0;
}