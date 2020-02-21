#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    ll dp[n+1][2][2] = {0};
    dp[0][0][0] = 1;
    dp[0][0][1] = 0;
    dp[0][1][0] = 0;
    dp[0][1][1] = 0;

    rep1(i, n+1){
        rep(smaller, 2){
            rep(j, 2){

                int c = s[i-1] - '0';

                dp[i][smaller || c < s[i-1]][j || c == 3] += dp[i-1][smaller][j];

            }
        }
        
    }

    cout << dp[n][0][1] + dp[n][1][1] << endl;

    return 0;
}