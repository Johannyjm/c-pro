#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    for(int i = 0; i < h; ++i) for(int j = 0; j < w; ++j) cin >> a[i][j];

    vector<vector<ll>> ressum(h, vector<ll>(w, 0));
    for(int si = 0; si < h; ++si){
        for(int sj = 0; sj < w; ++sj){
            if(ressum[si][sj] > 0) continue;

            queue<pair<int, int>> q;
            q.push({si, sj});
            ressum[si][sj] = -1;
            int cnt = 1;
            while(!q.empty()){
                pair<int, int> p = q.front();
                q.pop();
                
                int y = p.first;
                int x = p.second;
                for(int dir = 0; dir < 4; ++dir){
                    int ny = y + dy[dir];
                    int nx = x + dx[dir];

                    if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
                    if(a[ny][nx] <= a[y][x]) continue;
                    if(ressum[ny][nx] == -1) continue;

                    ressum[ny][nx] = ressum[y][x] - 1;
                    q.push({ny, nx});
                }
            }
            
            ressum[si][sj] = cnt;
            q.push({si, sj});
            while(!q.empty()){
                pair<int, int> p = q.front();
                q.pop();

                int y = p.first;
                int x = p.second;

                for(int dir = 0; dir < 4; ++dir){
                    int ny = y + dy[dir];
                    int nx = x + dx[dir];

                    if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
                    if(ressum[ny][nx] != -1) continue;

                    ressum[ny][nx] += cnt;
                    q.push({ny, nx});
                }
            }
        }
    }

    ll res = 0;

}
