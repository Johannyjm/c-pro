#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    int a[h][w];
    rep(i, h) rep(j, w) cin >> a[i][j];

    int res[h][w] = {0};

    //horizontal axis
    rep(i, h){
        bool drop_flg = true;
        rep(j, w){
            if(a[i][j]=='.') drop_flg = drop_flg && true;
            else drop_flg = false;
        }
        
    }
}