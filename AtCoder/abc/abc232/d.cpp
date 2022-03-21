#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int dy[] = {0, 1};
int dx[] = {1, 0};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    for(int i = 0; i < h; ++i) cin >> s[i];

    queue<pair<int, int>> q;
    q.push({0, 0});

    const int INF = 1001001001;
    vector<vector<int>> dist(h, vector<int>(w, INF));
    dist[0][0] = 0;

    int res = 0;
    while(!q.empty()){
        auto [y, x] = q.front();
        q.pop();

        for(int dir = 0; dir < 2; ++dir){
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
            if(dist[ny][nx] != INF) continue;
            if(s[ny][nx] == '#') continue;

            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny, nx});

            res = max(res, dist[ny][nx]);
        }
    }

    cout << res+1 << endl;
    
    return 0;
}
