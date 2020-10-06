#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    vector<pair<char, int>> dp;
    dp.push_back({s[0], 1});
    rep1(i, n){
        if(dp.back().first == s[i]) ++dp.back().second;
        else dp.push_back({s[i], 1});
    }

    // rep(i, dp.size()){
    //     cout << dp[i].first << " " << dp[i].second << endl;
    // }
    cout << dp.size()-1 << endl;

    return 0;
}