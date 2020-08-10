#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for(int i = 0; i < h; ++i) cin >> grid[i];
    int sy, sx, gy, gx;
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            if(grid[i][j] == 's'){
                sy = i;
                sx = j;
            }
            if(grid[i][j] == 'g'){
                gy = i;
                gx = j;
            }
        }
    }
    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {sy, sx}});
    const int INF = 1001001001;
    vector<vector<int>> dist(h, vector<int>(w, INF));
    dist[sy][sx] = 0;

    while(!pq.empty()){
        pair<int, pair<int, int>> p = pq.top();
        pq.pop();
        int y = p.second.first;
        int x = p.second.second;

        for(int dir = 0; dir < 4; ++dir){
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
            int cost = 0;
            if(grid[ny][nx] == '#') ++cost;

            if(dist[y][x] + cost < dist[ny][nx]){
                dist[ny][nx] = dist[y][x] + cost;
                pq.push({dist[ny][nx], {ny, nx}});
            }
        }
    }


    if(dist[gy][gx] <= 2) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
