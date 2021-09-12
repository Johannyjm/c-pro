#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    int cnt_w = 0;
    rep(i, h) rep(j, w){
        if(s[i][j] == '.') ++cnt_w;
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    const int INF = 1001001001;
    vector<vector<int>> dist(h, vector<int>(w, INF));
    dist[0][0] = 0;

    while(!q.empty()){
        auto [y, x] = q.front();
        q.pop();

        rep(dir, 4){
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
            if(dist[ny][nx] != INF) continue;
            if(s[ny][nx] == '#') continue;

            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny, nx});

        }
    }

    if(dist[h-1][w-1] == INF){
        cout << -1 << endl;
        return 0;
    }

    cout << cnt_w - dist[h-1][w-1] -1 << endl;

    return 0;
}