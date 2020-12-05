#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

double p(double i, double j){
    return 1 / (1 + pow(10, (j - i) / 400));
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int k;
    cin >> k;
    vector<double> R(1<<k);
    rep(i, 1<<k) cin >> R[i];

    vector<vector<double>> dp(k, vector<double>(1<<k, 0));
    rep(i, k){
        rep(j, 1<<k){
            if(i == 0){
                if(j%2==0) dp[i][j] = p(R[j], R[j+1]);
                else dp[i][j] = p(R[j], R[j-1]);

                continue;
            }

            int l, r;
            if(j%(1<<(i+1)) < 1<<i){
                l = j/(1<<(i))*(1<<(i)) + (1<<i);
                r = l+(1<<i);
            }
            else{
                l = j/(1<<(i))*(1<<(i)) - (1<<i);
                r = l+(1<<i);
            }

            for(int k = l; k < r; ++k){
                dp[i][j] += dp[i-1][j] * (dp[i-1][k]*p(R[j], R[k]));
            }
        }
    }

    cout << setprecision(20);
    for(auto res: dp[k-1]) cout << res << endl;

    return 0;
}