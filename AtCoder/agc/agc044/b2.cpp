#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
const int INF = 1001001001;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<vector<int>> grid(n+2, vector<int>(n+2, 0));
    rep(i, n+2){
        if(i==0 || i==n+1) continue;
        rep(j, n+2){
            if(j==0 || j==n+1) continue;
            grid[i][j] = -1;
        }
    }

    rep(_, n*n){
        int p;
        cin >> p;

        int sy = (p-1)/n + 1;
        int sx = p%n;
        if(p%n==0) sx = n;

        int mn = INF;
        rep(dir, 4){
            int ny = sy + dy[dir];
            int nx = sx + dx[dir];
            if(grid[ny][nx] == -1) continue;
            
            mn = min(mn, grid[ny][nx]);
        }

        if(mn == INF) grid



    return 0;
}