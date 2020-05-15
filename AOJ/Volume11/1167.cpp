#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<int> queries;
    int q_max = 0;
    while(1){
        int q;
        cin >> q;
        if(q == 0) break;
        queries.push_back(q);
        q_max = max(q_max, q);
    }

    int num = 0;
    vector<int> tetra;
    int x = 1;
    while(num <= q_max){
        num = x * (x+1) * (x+2) / 6;
        tetra.push_back(num);
        ++x;
    }

    int m = tetra.size();

    const int INF = 1001001001;
    vector<vector<int>> dp(2, vector<int>(q_max+1, INF)); // 0: all, 1: odd only
    dp[0][0] = 0;
    dp[1][0] = 0;
    rep1(i, q_max+1){
        rep(j, m){
            if(tetra[j] > i) break;
            dp[0][i] = min(dp[0][i], dp[0][i-tetra[j]] + 1);
            if(tetra[j]%2 == 1) dp[1][i] = min(dp[1][i], dp[1][i-tetra[j]] + 1);
        }
    }

    rep(i, queries.size()) cout << dp[0][queries[i]] << " " << dp[1][queries[i]] << endl;

    return 0;
}