#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int n;
string s;
int lcs(string a, string b){
    int p = a.size();
    int q = b.size();
    vector<vector<int>> dp(p+1, vector<int>(q+1, 0));
    rep1(i, p+1) rep1(j, q+1){
        if(a[i-1] == b[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
        dp[i][j] = max({dp[i][j], dp[i-1][j], dp[i][j-1]});
    }

    return dp[p][q];
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> s;
    
    int res = 0;
    rep(i, n){
        res = max(res, lcs(s.substr(0, i), s.substr(i, n)));
    }

    cout << n-res*2 << endl;

    return 0;
}