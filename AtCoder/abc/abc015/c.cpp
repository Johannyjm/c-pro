#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int n, k;
vector<vector<int>> t;
bool dfs(int idx, int curr){

    if(idx == n-1){
        if(curr == 0) return true;
        else return false;
    }

    bool ret = false;
    rep(i, k){
        if(dfs(idx+1, curr^t[idx+1][i])) ret = true;
    }

    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> k;

    t.resize(n, vector<int>(k));
    rep(i, n) rep(j, k) cin >> t[i][j];

    bool flg = false;
    rep(i, k){
        if(dfs(0, t[0][i])) flg = true;
    }

    if(flg) puts("Found");
    else puts("Nothing");


    return 0;
}