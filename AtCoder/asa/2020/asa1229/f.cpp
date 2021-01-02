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

    int h, w, k, si, sj, gi, gj;
    cin >> h >> w >> k >> si >> sj >> gi >> gj;

    --si;
    --sj;
    --gi;
    --gj;

    vector<string> s(h);
    rep(i, h) cin >> s[i];

    const int INF = 1001001001;
    vector<vector<int>> dist(h, vector<int>(w, INF));
    dist[si][sj] = 0;

    queue<pair<int, int>> q;
    q.push({si, sj});

    while(!q.empty()){
        pair<int, int> now = q.front();
        q.pop();

        int y = now.first;
        int x = now.second;

        rep(dir, 4){
            for(int gain = 1; gain <= k; ++gain){
                int ny = y + dy[dir] * gain;
                int nx = x + dx[dir] * gain;
                // cout << "y: " << y << ", x: " << x << ", ny: " << ny << ", nx: " << nx << endl;

                if(ny<0 || ny>=h || nx<0 || nx>=w) break;
                if(s[ny][nx] == '@') break;
                if(dist[ny][nx] != INF){
                    if(dist[ny][nx] < dist[y][x] + 1) break;
                    else continue;
                }
                // if(dist[ny][nx] < dist[y][x]+1) break;


                dist[ny][nx] = dist[y][x] + 1;
                q.push({ny, nx});
            }
        }
    }

    // rep(i, h){
    //     rep(j, w) cout << dist[i][j] << " ";
    //     cout << endl;
    // }


    if(dist[gi][gj] != INF) cout << dist[gi][gj] << endl;
    else cout << -1 << endl;

    return 0;
}