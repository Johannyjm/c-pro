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

    const int INF = 1001001001;
    vector<vector<int>> dist(h, vector<int>(w, INF));
    dist[0][0] = 0;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, 0}});

    while(!pq.empty()){
        pair<int, pair<int, int>> now = pq.top();
        pq.pop();
        int d = now.first;
        int y = now.second.first;
        int x = now.second.second;

        if(dist[y][x] != d) continue;

        // cost: 0
        rep(dir, 4){
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
            if(s[ny][nx] == '#') continue;

            if(dist[ny][nx] > dist[y][x]){
                dist[ny][nx] = dist[y][x];
                pq.push({dist[ny][nx], {ny, nx}});
            }
        }

        // cost: 1
        for(int i = -2; i <= 2; ++i){
            for(int j = -2; j <= 2; ++j){
                if(abs(i) + abs(j) == 4) continue;
                int ny = y + i;
                int nx = x + j;

                if(ny<0 || ny>=h || nx<0 || nx>=w) continue;

                if(dist[ny][nx] > dist[y][x] + 1){
                    dist[ny][nx] = dist[y][x] + 1;
                    pq.push({dist[ny][nx], {ny, nx}});
                }
            }
        }
    }

    cout << dist[h-1][w-1] << endl;

    return 0;
}