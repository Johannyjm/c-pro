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
    int stx, sty, gox, goy;
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            if(grid[i][j] == 's'){
                sty = i;
                stx = j;
            }
            if(grid[i][j] == 'g'){
                goy = i;
                gox = j;
            }
        }
    }
    
    const int INF = 1001001001;
    vector<vector<int>> dist(h, vector<int>(w, INF));
    int marker = 1;
    for(auto elem: {make_pair(sty, stx), make_pair(goy, gox)}){
        int sy = elem.first;
        int sx = elem.second;

        queue<pair<int, int>> q;
        q.push({sy, sx});
        dist[sy][sx] = marker;

        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            int y = p.first;
            int x = p.second;
            for(int dir = 0; dir < 4; ++dir){
                int ny = y + dy[dir];
                int nx = x + dx[dir];
                if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
                if(dist[ny][nx] != INF) continue;
                if(grid[ny][nx] == '#') continue;

                dist[ny][nx] = marker;
                if(marker == 1 && grid[ny][nx] == 'g'){
                    cout << "YES" << endl;
                    return 0;
                }
                q.push({ny, nx});
            }
        }

        ++marker;
    }

    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            if(dist[i][j] != 1) continue;
            bool nowall = true;
            for(int dir = 0; dir < 4; ++dir){
                int ny = i + dy[dir];
                int nx = j + dx[dir];

                if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
                if(dist[ny][nx] == INF){
                    for(int dir2 = 0; dir2 < 4; ++dir2){
                        int nny = ny + dy[dir2];
                        int nnx = nx + dx[dir2];
                        if(nny<0 || nny>=h || nnx<0 || nnx>=w) continue;
                        if(dist[nny][nnx] == 2){
                            cout << "YES" << endl;
                            return 0;
                        }
                        if(dist[nny][nnx] == INF){
                            for(int dir3 = 0; dir3 < 4; ++dir3){
                                int nnny = nny + dy[dir3];
                                int nnnx = nnx + dx[dir3];
                                if(nnny<0 || nnny>=h || nnnx<0 || nnnx>=w) continue;
                                if(dist[nnny][nnnx] == 2){
                                    cout << "YES" << endl;
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}
