#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<ll> s(n), t(m);
    rep(i, n) cin >> s[i];
    rep(i, m) cin >> t[i];

    vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));
    rep1(i, s.size()+1) rep1(j, t.size()+1){
        if(s[i-1] == t[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
        dp[i][j] = max({dp[i][j], dp[i-1][j], dp[i][j-1]});
    }

    // rep(i, n+1){
    //     rep(j, m+1) cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    // cout << dp[n][m] << endl;
    ll lcs = dp[n][m];


    vector<ll> ab;
    int i = s.size();
    int j = t.size();
    while(dp[i][j]!=0 && i!=0 && j!=0){
        while(dp[i][j] == dp[i-1][j]) --i;
        while(dp[i][j] == dp[i][j-1]) --j;
 
        ab.push_back(s[i-1]);
        --i;
        --j; 
    }
 
    reverse(ab.begin(), ab.end());

    // cout << max(n, m) << endl;

    ll res = 0;
    i = 0;
    j = 0;
    ab.push_back(-1);
    s.push_back(-2);
    t.push_back(-3);
    int ptr = 0;
    while(1){
        if(s[i]==ab[ptr] && t[j]==ab[ptr]){
            ++i;
            ++j;
            ++ptr;
        }
        else if(s[i]!=ab[ptr] && t[j]==ab[ptr]){
            ++res;
            ++i;
        }
        else if(s[i]==ab[ptr] && t[j]!=ab[ptr]){
            ++res;
            ++j;
        }
        else{
            ++res;
            ++i;
            ++j;
        }

        i = min(n, i);
        j = min(m, j);

        if(i==n && j==m) break;
    }
    // cout << i << " " << j << endl;
    res += n-i + m-j;
    cout << res << endl;


    return 0;
}