#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

string smax(string s, string t){
    if(s.size() != t.size()){
        if(s.size() > t.size()) return s;
        else return t;
    }
    if(s == t) return s;

    int n = s.size();
    rep(i, n){
        if(s[i] > t[i]) return s;
        if(t[i] > s[i]) return t;
    }

    return s;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    while(1){
        int w, h;
        cin >> w >> h;
        if(w == 0) break;

        vector<string> s(h);
        rep(i, h) cin >> s[i];

        vector<vector<string>> dp(h, vector<string>(w, ""));
        string res = "0";
        rep(i, h) rep(j, w){
            if('A'<=s[i][j]&&s[i][j]<='Z') continue;
            string sm = "";
            if(i > 0) sm = dp[i-1][j];
            if(j > 0) sm = smax(sm, dp[i][j-1]);
            while(sm[0] == '0') sm = sm.substr(1);
            dp[i][j] = sm + s[i][j];

            res = smax(res, dp[i][j]);
        }

        cout << res << endl;

    }

    return 0;
}