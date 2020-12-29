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

    const int INF = 1001001001;
    int res = 0;
    rep(si, h) rep(sj, w){
        if(s[si][sj] == '#') continue;
        
        vector<vector<int>> dist(h, vector<int>(w, INF));
        dist[si][sj] = 0;
        queue<pair<int, int>> q;
        q.push({si, sj});

        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();

            int y = p.first;
            int x = p.second;
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

        int cand = 0;
        rep(i, h) rep(j, w){
            if(dist[i][j]!=INF) cand = max(cand, dist[i][j]);
        }

        res = max(res, cand);

        // cout << endl;
        // rep(i, h){
        //     rep(j, w) cout << dist[i][j] << " ";
        //     cout << endl;
        // }

        // cout << endl;
    }

    cout << res << endl;

    return 0;
}