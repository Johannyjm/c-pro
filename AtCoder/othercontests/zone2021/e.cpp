#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

ll a[550][550];
ll b[550][550];
ll dist[550][550];

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll h, w;
    cin >> h >> w;

    rep(i, h) rep(j, w-1) cin >> a[i][j];
    rep(i, h-1) rep(j, w) cin >> b[i][j];

    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> pq;
    pq.push({0, {0, 0}});

    const ll INF = 1ll<<60;
    rep(i, h) rep(j, w) dist[i][j] = INF;
    dist[0][0] = 0;

    const int dy[] = {0, 0, 1};
    const int dx[] = {1, -1, 0};

    while(!pq.empty()){
        pair<ll, pair<int, int>> p = pq.top();
        pq.pop();
        pair<int, int> now = p.second;
        int y = now.first;
        int x = now.second;

        rep(dir, 3){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
            ll cost;
            if(dir == 0) cost = a[y][x];
            if(dir == 1) cost = a[ny][nx];
            if(dir == 2) cost = b[y][x];

            if(dist[ny][nx] > dist[y][x] + cost){
                dist[ny][nx] = dist[y][x] + cost;
                pq.push({dist[ny][nx], {ny, nx}});
            }
        }

        rep1(i, y+1){
            int ny = y-i;
            int nx = x;
            // cout << y << " " << x << " " << ny << " " << nx << endl;
            if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
            ll cost = i+1;

            if(dist[ny][nx] > dist[y][x] + cost){
                dist[ny][nx] = dist[y][x] + cost;
                pq.push({dist[ny][nx], {ny, nx}});
            }
        }
    }    

    // rep(i, h){
    //     rep(j, w) cout << dist[i][j] << " ";
    //     cout << endl;
    // }

    cout << dist[h-1][w-1] << endl;


    return 0;
}