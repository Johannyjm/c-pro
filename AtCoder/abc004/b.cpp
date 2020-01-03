#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n = 4;
    char c[n][n];

    rep(i, n){
        rep(j, n) cin >> c[i][j];
    }

    char res[n][n];
    rep(i, n){
        rep(j, n){
            res[i][j] = c[n-i-1][n-j-1];
        }
    }

    rep(i, n){
        rep(j, n) cout << res[i][j] << " ";
        cout << endl;
    }

}