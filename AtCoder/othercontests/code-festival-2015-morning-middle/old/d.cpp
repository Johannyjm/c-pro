#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int n, R;
int dp[110][110][110];
string s;
int rec(int l, int r){
    if(dp[l][r][R] != 0) return dp[l][r][R];
    int ret = 0;
    for(int i = l+1; i < R; ++i){
        for(int j = r+1; j < n; ++j){
            if(s[i] == s[j]){
                ret = max(ret, rec(i, j)+1);
            }
        }
    }
    return ret = dp[l][r][R];
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> s;

    int res = 0;
    rep(l, n){
        for(int r = l+1; r < n; ++r){
            if(s[l] == s[r]){
                R = r;
                int val = rec(l, r)+1;
                // cout << l << " " << r << " " << val << endl;
                res = max(res, val);
            }
        }
    }

    cout << n-res*2 << endl;

    return 0;
}