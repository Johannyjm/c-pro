#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, gx, gy;
    cin >> n >> gx >> gy;
    gx += 220;
    gy += 220;

    int sx = 220;
    int sy = 220;

    int N = 440;

    vector<vector<char>> grid(N, vector<char>(N, '.'));
    grid[sy][sx] = 'S';
    grid[gy][gx] = 'G';
    rep(_, n){
        int xx, yy;
        cin >> xx >> yy;

        xx += 220;
        yy += 220;

        grid[yy][xx] = '#';
    }

    // for(int i = 190; i < 210; ++i){
    //     for(int j = 190; j < 210; ++j) cout << grid[i][j];
    //     cout << endl;
    // }

    const int dy[] = {1, 1, 1, 0, 0, -1};
    const int dx[] = {1, 0, -1, 1, -1, 0};

    queue<pair<int, int>> q;
    q.push(make_pair(sy, sx));
    const int INF = 1001001001;
    vector<vector<int>> dist(N, vector<int>(N, INF));
    dist[sy][sx] = 0;
    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        int y = p.first;
        int x = p.second;

        rep(dir, 6){
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if(ny<0 || ny>=N || nx<0 || nx>=N) continue;
            if(dist[ny][nx] != INF) continue;
            if(grid[ny][nx] == '#') continue;

            dist[ny][nx] = dist[y][x] + 1;
            q.push(make_pair(ny, nx));

        }
    }

    if(dist[gy][gx] == INF) cout << -1 << endl;
    else cout << dist[gy][gx] << endl;


    return 0;
}