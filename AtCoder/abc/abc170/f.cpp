#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w, k;
    cin >> h >> w >> k;
    int si, sj, gi, gj;
    cin >> si >> sj >> gi >> gj;
    --si;
    --sj;
    --gi;
    --gj;

    vector<string> c(h);
    rep(i, h) cin >> c[i];

    queue<pair<int, int>> q;
    q.push(make_pair(si, sj));
    
    const int INF = 1001001001;
    vector<vector<int>> dist(h, vector<int>(w, INF));
    dist[si][sj] = 0;

    const int di[] = {0, 1, 0, -1};
    const int dj[] = {1, 0, -1, 0};

    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        int y = p.first;
        int x = p.second;

        rep(dir, 4){
            for(int i = 1; i <= k; ++i){
                int ny = y + di[dir]*i;
                int nx = x + dj[dir]*i;

                if(ny>=h || ny<0 || nx>=w || nx<0) break;
                if(c[ny][nx] == '@') break;
                if(dist[ny][nx] != INF){
                    if(dist[ny][nx] <= dist[y][x]) break;
                    else continue;
                }

                dist[ny][nx] = dist[y][x] + 1;

                q.push(make_pair(ny, nx));
            }
        }
    }

    // rep(i, h){
    //     rep(j, w) {
    //         if(dist[i][j] != INF) cout << dist[i][j] << " ";
    //         else cout << '@' << " ";
    //     }
    //     cout << endl;
    // }

    if(dist[gi][gj] != INF) cout << dist[gi][gj] << endl;
    else cout << -1 << endl;

    return 0;
}