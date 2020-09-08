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

    ll dp[n+1][2][8] = {0};
    dp[0][0][0] = 1;

    rep(i, n){
        rep(j, 2){
            rep(k, 8){
                int c = s[i] - '0';
                rep(nxt, 10){
                    if(c<nxt && j==0) continue;

                    int dgt = i + 1;

                    int isless = j;
                    if(nxt < c) isless = 1;

                    int k2 = k;
                    if(c==3)k2 += 1;
                    if(c==5)k2 += 2;
                    if(c==7)k2 += 4;

                    dp[i + 1][isless][k2] += dp[i][j][k];
                }
            }
        }
    }

    cout << dp[n][0][7] + dp[n][1][7] << endl;

    return 0;
}
