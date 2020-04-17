#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<vector<int>> d(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> d[i][j];

    vector<int> dp(n, 0);
    rep1(i, n+1){
        int mx = -1;
        rep(j, n){
            rep(k, n-i+1){
                int sm1 = 0;
                int sm2 = 0;
                rep(l, i) {
                    sm1 += d[j][l+k];
                    sm2 += d[l+k][j];
                }
                mx = max({mx, sm1, sm2});
            }
        }

        

    }

    return 0;
}