#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int r, c, sy, sx, gy, gx;
    cin >> r >> c >> sy >> sx >> gy >> gx;
    --sy;
    --sx;
    --gy;
    --gx;

    vector<string> grid(r);
    rep(i, r) cin >> grid[i];

    vector<vector<int>> dist(r, vector<int>(c, -1));
    dist[sy][sx] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(sy, sx));

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        rep(dir, 4){
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if(ny<0 || ny>=r || nx<0 || nx>=c) continue;
            if(grid[ny][nx] == '#') continue;
            if(dist[ny][nx] != -1) continue;

            dist[ny][nx] = dist[y][x] + 1;
            q.push(make_pair(ny, nx));
        }
    }

    cout << dist[gy][gx] << endl;

    return 0;
}