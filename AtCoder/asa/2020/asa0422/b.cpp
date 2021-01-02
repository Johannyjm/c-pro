#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<vector<int>> c(3, vector<int>(3));
    rep(i, 3) rep(j, 3) cin >> c[i][j];

    int s1 = c[0][1] - c[0][0];
    int s2 = c[0][2] - c[0][1];
    
    if(c[1][1]-c[1][0] == s1 && c[1][2]-c[1][1] == s2 && c[2][1]-c[2][0] == s1 && c[2][2]-c[2][1] == s2) puts("Yes");
    else puts("No");

    return 0;
}