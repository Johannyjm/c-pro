#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;

    vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));
    rep1(i, s.size()+1) rep1(j, t.size()+1){
        if(s[i-1] == t[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
        dp[i][j] = max({dp[i][j], dp[i-1][j], dp[i][j-1]});
    }

    // rep(i, s.size()+1){
    //     rep(j, t.size()+1) cout << dp[i][j] << " ";
    //     cout << endl;
    // }

    string res = "";
    int i = s.size();
    int j = t.size();
    while(dp[i][j]!=0 && i!=0 && j!=0){
        while(dp[i][j] == dp[i-1][j]) --i;
        while(dp[i][j] == dp[i][j-1]) --j;

        res += s[i-1];
        --i;
        --j; 
    }

    reverse(res.begin(), res.end());

    cout << res << endl;

    return 0;
}