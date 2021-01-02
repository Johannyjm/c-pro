#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h = 4;
    int w = 4;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> a[i][j];

    const int dy[] = {0, 1, 0, -1};
    const int dx[] = {1, 0, -1, 0};

    rep(y, h) rep(x, w){
        rep(dir, 4){
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if(ny>=h || ny<0 || nx>=w || nx<0) continue;
            if(a[ny][nx] == a[y][x]){
                puts("CONTINUE");
                return 0;
            }
        }
    }

    puts("GAMEOVER");

    return 0;
}