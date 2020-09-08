#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    char a[h][w];

    rep(i, h){
        rep(j, w){
            cin >> a[i][j];
        }
    }

    rep(i, h+2){
        cout << '#';
        rep(j, w){
            if(i == 0 || i == h+1) cout << '#';
            else cout << a[i-1][j];
        }
        cout << '#' << endl;
    }
}