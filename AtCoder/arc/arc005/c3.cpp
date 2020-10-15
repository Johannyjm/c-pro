#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    int sy, sx, gy, gx;
    rep(i, h) rep(j, w){
        if(s[i][j] == 's'){
            sy = i;
            sx = j;
        }
        if(s[i][j] == 'g'){
            gy = i;
            gx = j;
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

        rep(dir, 4){
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
            int cost = 0;
            if(s[ny][nx] == '#') ++cost;

            if(dist[y][x] + cost < dist[ny][nx]){
                dist[ny][nx] = dist[y][x] + cost;
                pq.push({dist[ny][nx], {ny, nx}});
            }
        }
    }

    if(dist[gy][gx] <= 2) puts("YES");
    else puts("NO");

    return 0;
}