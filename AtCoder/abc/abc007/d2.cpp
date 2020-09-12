#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll digit(ll num){
    vector<ll> di;
    while(num){
        di.push_back(num%10);
        num /= 10;
    }

    reverse(di.begin(), di.end());
    
    int n = di.size();
    ll dp[n+1][2][2] = {};
    dp[0][0][0] = 1;

    for(int i = 0; i < n; ++i){
        int D = di[i];
        for(int j = 0; j < 2; ++j){
            for(int k = 0; k < 2; ++k){
                for(int d = 0; d <= (j? 9: D); ++d){
                    dp[i+1][j||(d<D)][k||(d==4)||(d==9)] += dp[i][j][k];
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

    cout << digit(b) - digit(a-1) << endl;

    return 0;
}
