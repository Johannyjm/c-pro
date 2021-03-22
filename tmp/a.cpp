#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for(int i = 0; i < h; ++i) cin >> s[i];
    
    const int INF = 1001001001;
    vector<vector<int>> dist(h, vector<int>(w, INF));
    dist[0][0] = 0;

    queue<pair<int, int>> q;
    q.push({0, 0});

    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();

        int y = p.first;
        int x = p.second;
        for(int dir = 0; dir < 4; ++dir){
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
            if(s[ny][nx] == '#') continue;
            if(dist[ny][nx] != INF) continue;

            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny, nx});
        }
    }

    cout << dist[h-1][w-1] << endl;


    return 0;
}
