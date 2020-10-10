#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n = 4;
    vector<vector<char>> c(n, vector<char>(n));
    rep(i, n) rep(j, n) cin >> c[i][j];

    rep(i, n){
        rep(j, n) cout << c[n-i-1][n-j-1] << " ";
        cout << endl;
    }

    return 0;
}