#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

vector<int> w;
vector<vector<int>> dp;
int rec(int l, int r){
    if(dp[l][r] != -1) return dp[l][r];
    if(abs(l-r) <= 1) return dp[l][r] = 0;
    
    int ret = 0;
    if(abs(w[l] - w[r-1]) <= 1 && rec(l+1, r-1) == r-l-2) ret = r-l;

    for(int m = l+1; m <= r-1; ++m){
        ret = max(ret, rec(l, m) + rec(m, r));
    }

    return dp[l][r] = ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    dp.resize(330, vector<int>(330));
    while(true){
        int n;
        cin >> n;

        if(n == 0) return 0;

        w.resize(n);
        rep(i, n) cin >> w[i];

        dp.assign(330, vector<int>(330, -1));
        cout << rec(0, n) << endl;

    }

    return 0;
}