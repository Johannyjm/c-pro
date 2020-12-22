#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];

    int mn = 1001001001;
    rep(i, h) rep(j, w){
        mn = min(mn, a[i][j]);
    }

    int res = 0;
    rep(i, h) rep(j, w) res += (a[i][j]) - mn;

    cout << res << endl;


    return 0;
}