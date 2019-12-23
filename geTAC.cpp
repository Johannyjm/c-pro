#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    int dp[n] = {0};

    for(int i = 1; i < s.length(); ++i){
        string subs = s.substr(i-1, 2);
        
        if(subs == "AC") dp[i] = dp[i-1] + 1;
        else dp[i] = dp[i-1];
    } 

    for (int i = 0; i < q; ++i){
        int l, r;
        cin >> l >> r;
        cout << dp[r-1] - dp[l-1] << endl;
    }
}