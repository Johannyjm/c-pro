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
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    int sy = -1;
    int sx = -1;
    int gy = -1;
    int gx = -1;
    vector<vector<pair<int, int>>> warps(26);
    rep(i, h) rep(j, w){
        if(s[i][j] == 'S'){
            sy = i;
            sx = j;
        }
        if(s[i][j] == 'G'){
            gy = i;
            gx = j;
        }

        if('a'<=s[i][j]&&s[i][j]<='z'){
            warps[s[i][j]-'a'].push_back({i, j});
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {sy, sx}});
    const int INF = 1001001001;
    vector<vector<int>> dist(h, vector<int>(w, INF));
    dist[sy][sx] = 0;

    while(!pq.empty()){
        pair<int, pair<int, int>> pp = pq.top();
        pq.pop();
        int y = pp.second.first;
        int x = pp.second.second;

        rep(dir, 4){
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
            if(s[ny][nx] == '#') continue;

            if(dist[ny][nx] > dist[y][x] + 1){
                dist[ny][nx] = dist[y][x] + 1;
                pq.push({dist[ny][nx], {ny, nx}});
            }
        }

        if('a'<=s[y][x] && s[y][x]<='z'){
            int ny = -1;
            int nx = -1;
            if(warps[s[y][x]-'a'][0].first == y){
                ny = warps[s[y][x]-'a'][1].first;
                nx = warps[s[y][x]-'a'][1].second;
            }
            else{
                ny = warps[s[y][x]-'a'][0].first;
                nx = warps[s[y][x]-'a'][0].second;
            }

            if(dist[ny][nx] > dist[y][x] + 1){
                dist[ny][nx] = dist[y][x] + 1;
                pq.push({dist[ny][nx], {ny, nx}});
            }
        }
    }

    if(dist[gy][gx] == INF) cout << -1 << endl;
    else cout << dist[gy][gx] << endl;

    return 0;
}