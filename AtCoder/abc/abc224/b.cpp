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

    vector<vector<ll>> a(h, vector<ll>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];
    
    rep(i1, h) rep(i2, h) rep(j1, w) rep(j2, w){
        if(i1 > i2) continue;
        if(j1 > j2) continue;
        if(a[i1][j1] + a[i2][j2] > a[i2][j1] + a[i1][j2]){
            puts("No");
            return 0;
        }
    }

    puts("Yes");

    return 0;
}