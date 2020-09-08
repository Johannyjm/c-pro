#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n = 4;
    vector<vector<int>> a(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> a[i][j];

    // hirizontal
    rep(i, n){
        if(a[i][0]==a[i][1] || a[i][1]==a[i][2] || a[i][2]==a[i][3]){
            puts("CONTINUE");
            return 0;
        }
    }

    // vertical
    rep(i, n){
        if(a[0][i]==a[1][i] || a[1][i]==a[2][i] || a[2][i]==a[3][i]){
            puts("CONTINUE");
            return 0;
        }
    }

    puts("GAMEOVER");

    return 0;
}