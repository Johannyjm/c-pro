#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<string> field(10);
    rep(i, 10) cin >> field[i];

    const int dy[] = {0, 1, 0, -1};
    const int dx[] = {1, 0, -1, 0};

    rep(si, 10) rep(sj, 10){
        queue<pair<int, int>> q;
        q.push(make_pair(si, sj));

        const int INF = 1001001001;
        vector<vector<int>> dist(10, vector<int>(10, INF));
        dist[si][sj] = 0;

        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            int y = p.first;
            int x = p.second;

            rep(dir, 4){
                int ny = y + dy[dir];
                int nx = x + dx[dir];

                if(ny>=10 || ny<0 || nx>=10 || nx<0) continue;
                if(field[ny][nx] == 'x') continue;
                if(dist[ny][nx] != INF) continue;

                dist[ny][nx] = dist[y][x] + 1;
                q.push(make_pair(ny, nx));
            }
        }

        bool flg = true;
        rep(i, 10) rep(j, 10){
            if(field[i][j]=='o' && dist[i][j]==INF){
                flg = false;
                break;
            }
        }

        if(flg){
            puts("YES");
            return 0;
        }
    }
    
    puts("NO");

    return 0;
}