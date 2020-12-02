#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, c;
    cin >> n >> c;
    vector<vector<int>> dp(33, vector<int>(110000, 0));
    rep(i, n){
        int s, t, u;
        cin >> s >> t >> u;

        ++dp[u][s];
        --dp[u][t];
    }

    rep(i, 33){
        rep(j, 105000) dp[i][j+1] += dp[i][j];
    }

    vector<pair<int, int>> rs;
    rep(i, 33){
        rep(j, 105000){
            if(dp[i][j+1]==0 && dp[i][j]==1) rs.push_back({i, j+1});
        }
    }

    for(auto e: rs){
        dp[e.first][e.second] += 1;
    }

    int res = 0;
    rep(i, 105000){
        int cnt = 0;
        rep(j, 33){
            cnt += dp[j][i];
        }

        res = max(res, cnt);
    }

    cout << res << endl;

    return 0;
}