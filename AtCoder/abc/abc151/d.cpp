#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

const int INF = 1001001001;
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];


    int res = 0;
    queue<pair<int, int>> q;
    vector<vector<int>> dist(h, vector<int>(w, INF));
    rep(si, h) rep(sj, w){
        if(s[si][sj] == '#') continue;
        
        q.push({si, sj});
        dist.assign(h, vector<int>(w, INF));
        dist[si][sj] = 0;

        while(!q.empty()){
            pair<int, int> now = q.front();
            q.pop();
            int y = now.first;
            int x = now.second;

            rep(dir, 4){
                int ny = y + dy[dir];
                int nx = x + dx[dir];

                if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
                if(s[ny][nx] == '#') continue;
                if(dist[ny][nx] != INF) continue;

                dist[ny][nx] = dist[y][x] + 1;
                q.push({ny, nx});
            }
        }

        int cand = 0;
        rep(i, h) rep(j, w){
            if(dist[i][j] != INF) cand = max(cand, dist[i][j]);
        }

        res = max(res, cand);
    }

    cout << res << endl;

    return 0;
}