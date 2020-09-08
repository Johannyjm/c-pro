#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    char s[n][n];
    rep(i, n){
        rep(j, n) cin >> s[i][j];
    }

    char res[n][n];

    rep(i, n){
        rep(j, n){
            res[i][j] = s[n-j-1][i];
        }
    }

    rep(i, n){
        rep(j, n) cout << res[i][j];
        cout << endl;
    }
}