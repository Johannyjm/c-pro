#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    int si, sj, gi, gj;
    cin >> si >> sj >> gi >> gj;
    --si;
    --sj;
    --gi;
    --gj;

    vector<string> s(h);
    rep(i, h) cin >> s[i];

    const int INF = 1001001001;
    vector<vector<int>> dist(h, vector<int>(w, INF));
    dist[si][sj] = 0;

    deque<pair<int, int>> dq;
    dq.push_front({si, sj});
    while(!dq.empty()){
        pair<int, int> p = dq.front();
        dq.pop_front();

        int y = p.first;
        int x = p.second;

        for(int dy = -2; dy <= 2; ++dy){
            for(int dx = -2; dx <= 2; ++dx){
                int ny = y + dy;
                int nx = x + dx;
                
                if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
                if(s[ny][nx] == '#') continue;
                if(dist[ny][nx] <= dist[y][x]) continue;

                if(dy*dx == 0 && abs(dy+dx)==1){
                    dist[ny][nx] = dist[y][x];
                    dq.push_front({ny, nx});
                }
                else{
                    dist[ny][nx] = dist[y][x] + 1;
                    dq.push_back({ny, nx});
                }
            }
        }

    }

    // rep(i, h){
    //     rep(j, w) cout << dist[i][j] << " ";
    //     cout << endl;
    // }

    if(dist[gi][gj] == INF) dist[gi][gj] = -1;
    cout << dist[gi][gj] << endl;

    return 0;
}