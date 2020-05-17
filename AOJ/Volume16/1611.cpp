#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int n;
vector<vector<int>> dp;

int solve(vector<int> w, int i){
    w[i] = -1;
    w[i+1] = -1;

    bool flg = true;
    rep(i, n-1){
        if(w[i] == -1) continue;
        int ptr = 0;
        while(i+1 + ptr < n && w[i+1 + ptr] == -1){
            ++ptr;
        }
        if(abs(w[i] - w[i+1 + ptr]) <= 1) {
            flg = false;
            break;
        }
    }

    if(flg){
        dp[0][i] == 
    }

    rep(i, n-1){
        if(w[i] == -1) continue;
        int ptr = 0;
        while(i+1 + ptr < n && w[i+1 + ptr] == -1){
            ++ptr;
        }
        if(abs(w[i] - w[i+1 + ptr]) <= 1){
            int ret = solve(w, i);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    vector<int> w(n);
    rep(i, n) cin >> w[i];

    dp.resize(n, vector<int>(n, 0));

    int res = 0;
    rep(i, n-1){
        if(abs(w[i] - w[i+1]) <= 1) res = max(res, solve(w, i));
    }

    cout << res << endl;

    return 0;
}