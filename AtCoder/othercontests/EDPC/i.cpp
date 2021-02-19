#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
using ld = long double;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<ld> p(n);
    for(int i = 0; i < n; ++i) cin >> p[i];

    vector<vector<ld>> dp(n+10, vector<ld>(n+10, 0));
    dp[0][0] = 1.0 - p.front();
    dp[0][1] = p.front();

    for(int i = 1; i < n+1; ++i){
        for(int j = 0; j < n+1; ++j){
            if(j == 0){
                dp[i][j] = dp[i-1][j] * (1 - p[i]);
                continue;
            }
            
            dp[i][j] = dp[i-1][j] * (1 - p[i]) + dp[i-1][j-1] * p[i];
        }
    }

    ld res = 0.0;
    for(int i = 0; i < n+1; ++i){
        if(i <= n/2) continue;
        res += dp[n-1][i];
    }

    cout << setprecision(20);
    cout << res << endl;

//#    for(int i = 0; i < n; ++i){
//#        for(int j = 0; j < n+1; ++j) cout << dp[i][j] << " ";
//#        cout << endl;
//#    }

    return 0;
}
