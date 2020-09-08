#include <iostream>
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
    vector<vector<int>> a(h, vector<int>(w));
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j) cin >> a[i][j];
    }

    vector<vector<bool>> seen(h, vector<bool>(w, false));
    vector<vector<int>> res;

    for(int sy = 0; sy < h; ++sy){
        for(int sx = 0; sx < w; ++sx){
            if(a[sy][sx] % 2 == 0) continue;
            if(seen[sy][sx]) continue;

            queue<pair<int, int>> q;
            q.push(make_pair(sy, sx));
            const int INF = 1001001001;
            vector<vector<int>> dist(h, vector<int>(w, INF));
            dist[sy][sx] = 0;

            int gy = -1;
            int gx = -1;
            bool flg = false;
            while(!q.empty()){
                pair<int, int> p = q.front();
                q.pop();
                int y = p.first;
                int x = p.second;
                
                for(int dir = 0; dir < 4; ++dir){
                    int ny = y + dy[dir];
                    int nx = x + dx[dir];
                    
                    if(ny>=h || ny<0 || nx>=w || nx<0) continue;
                    if(dist[ny][nx] != INF) continue;
                    if(seen[ny][nx]) continue;
                    
                    dist[ny][nx] = dist[y][x] + 1;
                    if(a[ny][nx] % 2 == 1){
                        gy = ny;
                        gx = nx;
                        flg = true;
                        break;
                    }
                    q.push(make_pair(ny, nx));
                }

                if(flg) break;
            }
            
            if(gy == -1) continue;

            seen[gy][gx] = true;
            int y = gy;
            int x = gx;
            vector<vector<int>> route;
            while(1){
                
                bool flg = false;
                for(int dir = 0; dir < 4; ++dir){
                    int ny = y + dy[dir];
                    int nx = x + dx[dir];
                    if(ny>=h || ny<0 || nx>=w || nx<0) continue;
                    if(seen[ny][nx]) continue;
                    if(dist[ny][nx] != dist[y][x] - 1) continue;
                    
                    seen[ny][nx] = true;
                    route.push_back({ny+1, nx+1, y+1, x+1});

                    if(ny == sy && nx == sx){
                        flg = true;
                        break;
                    }
                    y = ny;
                    x = nx;
                    break;
                }

                if(flg) break;
            }

            for(int i = 0; i < route.size(); ++i){
                res.push_back(route[route.size()-i-1]);
            }
        }
    }

    cout << res.size() << endl;
    for(int i = 0; i < res.size(); ++i){
        for(int j = 0; j < 3; ++j) cout << res[i][j] << " ";
        cout << res[i][3] << endl;
    }
}









