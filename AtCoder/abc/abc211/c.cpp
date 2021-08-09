#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string t = " chokudai";
    vector<ll> dp(9, 0);
    dp[0] = 1;

    string s;
    cin >> s;
    int n = s.size();

    rep(i, n){
        rep(j, 9){
            if(s[i] == t[j]){
                dp[j] = (dp[j-1] + dp[j]) % 1000000007;
            }
        }
    }

    cout << dp[8] << endl;

    return 0;
}