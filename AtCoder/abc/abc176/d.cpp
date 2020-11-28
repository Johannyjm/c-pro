#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    int sy, sx, gy, gx;
    cin >> sy >> sx >> gy >> gx;
    --sy;
    --sx;
    --gy;
    --gx;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    const int INF = 1001001001;
    vector<vector<int>> dist(h, vector<int>(w, INF));
    dist[sy][sx] = 0;

    deque<pair<int, int>> dq;
    dq.push_back({sy, sx});

    while(!dq.empty()){
        pair<int, int> now = dq.front();
        dq.pop_front();
        int y = now.first;
        int x = now.second;

        for(int di = -2; di <= 2; ++di){
            for(int dj = -2; dj <= 2; ++dj){
                int ny = y + di;
                int nx = x + dj;

                if(ny<0||ny>=h||nx<0||nx>=w) continue;
                if(s[ny][nx] == '#') continue;

                int cost = 1;
                if(di*dj==0&&abs(di+dj)==1) cost = 0;

                if(dist[ny][nx] <= dist[y][x]+cost) continue;

                dist[ny][nx] = dist[y][x] + cost;
                if(cost == 0) dq.push_front({ny, nx});
                if(cost == 1) dq.push_back({ny, nx});
            }
        }
    }

    if(dist[gy][gx] == INF) cout << -1 << endl;
    else cout << dist[gy][gx] << endl;

    return 0;
}