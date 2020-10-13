#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    int h = ty-sy;
    int w = tx-sx;

    rep(_, h) cout << 'U';
    rep(_, w) cout << 'R';
    rep(_, h) cout << 'D';
    rep(_, w) cout << 'L';
    cout << 'L';
    rep(_, h+1) cout << 'U';
    rep(_, w+1) cout << 'R';
    cout << "DR";
    rep(_, h+1) cout << 'D';
    rep(_, w+1) cout << 'L';
    cout << 'U' << endl;

    return 0;
}