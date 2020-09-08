#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

void dfs(vector<vector<int>> grid, int sy, int sx){
    rep(dir, 4){
        int ny = sy + dy[dir];
        int nx = sx + dx[dir];

        if(grid[ny][nx] == 0){
            grid[ny][nx] = -10;
            dfs(grid, ny, nx);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<vector<int>> grid(n+2, vector<int>(n+2, -10));
    rep(i, n+2){
        if(i==0 || i==n+1) continue;
        rep(j, n+2){
            if(j==0 || j==n+1) continue;
            grid[i][j] = 1;
        }
    }

    // rep(i, n+2){
    //     rep(j, n+2) cout << grid[i][j] << " ";
    //     cout << endl;
    // }

    int res = 0;
    rep(_, n*n){
        int p;
        cin >> p;

        int sy = (p-1)/n + 1;
        int sx = p%n;
        if(p%n==0) sx = n;

        grid[sy][sx] = 0;
        rep(dir, 4){
            int ny = sy + dy[dir];
            int nx = sx + dx[dir];
            if(grid[ny][nx] == -10){
                grid[sy][sx] = -10;
                dfs(grid, sy, sx);
            }
        }

        vector<vector<int>> dist(n+2, vector<int>(n+2, -1));
        dist[sy][sx] = 0;
        queue<pair<int, int>> q;
        q.push(make_pair(sy, sx));
        bool flg = false;
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();

            int y = p.first;
            int x = p.second;

            rep(dir, 4){
                int ny = y + dy[dir];
                int nx = x + dx[dir];

                if(ny<0 || ny>=n+2 || nx<0 || nx>=n+2) continue;
                if(grid[ny][nx] == -10){
                    flg = true;
                    res += dist[y][x];
                    break;
                }
                if(dist[ny][nx] != -1) continue;

                dist[ny][nx] = dist[y][x] + grid[ny][nx];
                q.push(make_pair(ny, nx));

            }
            if(flg){
                break;
            }

            rep(i, n+2){
                rep(j, n+2) cout << grid[i][j] << " ";
                cout << endl;
            }

        }

        // if(!flg){
        //     ++res;

            // const int INF = 1001001001;
            // vector<vector<int>> dist(n+2, vector<int>(n+2, INF));
            // dist[sy][sx] = 0;
            // vector<vector<bool>> seen(n+2, vector<bool>(n+2, false));
            // seen[sy][sx] = true;
            // priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
            // pq.push(make_pair(0, make_pair(sy, sx)));

            // int cost = INF;
            // while(!pq.empty()){
            //     pair<int, pair<int, int>> pp = pq.top();
            //     pq.pop();

            //     int y = pp.second.first;
            //     int x = pp.second.second;

            //     rep(dir, 4){
            //         int ny = y + dy[dir];
            //         int nx = x + dx[dir];
            //         if(ny<0 || ny>=n+2 || nx<0 || nx>=n+2) continue;
            //         if(seen[ny][nx]) continue;
            //         seen[ny][nx] = true;

            //         if(dist[y][x] + grid[ny][nx] < dist[ny][nx]){
            //             dist[ny][nx] = dist[y][x] + grid[ny][nx];
            //             pq.push(make_pair(dist[ny][nx], make_pair(ny, nx)));

            //             if(ny==0 || ny==n+1 || nx==0 || nx==n+1){
            //                 flg = true;
            //                 cost = min(cost, dist[ny][nx]);
            //             }

            //         }
            //     }
            //     if(flg) break;

            // }

            
            // rep(i, n+2) cost = min(cost, dist[0][i]);
            // rep(i, n+2) cost = min(cost, dist[n+1][i]);
            // rep(i, n+2) cost = min(cost, dist[i][0]);
            // rep(i, n+2) cost = min(cost, dist[i][n+1]);

            // res += cost;
        // }
        
        // cout << endl;
        // cout << endl;
        // cout << p << endl;
        // if(flg) cout << 1 << endl;
        // else cout << 0 << endl;
        // rep(i, n+2){
        //     rep(j, n+2) cout << grid[i][j] << " ";
        //     cout << endl;
        // }
        // rep(i, n+2){
        //     rep(j, n+2) cout << dist[i][j] << " ";
        //     cout << endl;
        // }
    }

    cout << res << endl;

    return 0;
}