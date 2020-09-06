#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
using ll = long long;

int h, w, t;
int si, sj, gi, gj;
vector<string> s;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
const ll INF = 1ll << 60;

bool check(int cost){
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {si, sj}});
    vector<vector<ll>> dist(h, vector<ll>(w, INF));
    dist[si][sj] = 0;

    while(!pq.empty()){
        pair<int, int> now = pq.top().second;
        pq.pop();
        int y = now.first;
        int x = now.second;

        for(int dir = 0; dir < 4; ++dir){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            
            if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
            
            int c = 1;
            if(s[ny][nx] == '#') c = cost;
            
            if(dist[ny][nx] > dist[y][x] + c){
                dist[ny][nx] = dist[y][x] + c;
                pq.push({dist[ny][nx], {ny, nx}});
            }
        }
    }

    if(dist[gi][gj] <= t) return true;
    else return false;
}


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> h >> w >> t;
    s.resize(h);
    for(int i = 0; i < h; ++i) cin >> s[i];

    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            if(s[i][j] == 'S'){
                si = i;
                sj = j;
            }
            if(s[i][j] == 'G'){
                gi = i;
                gj = j;
            }
        }
    }

    int ok = 1;
    int ng = 1000000000;

    while(ng-ok > 1){
        int mid = (ok+ng) / 2;

        if(check(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
    
    return 0;
}
