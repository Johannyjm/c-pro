#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

const int mod = 1000000007;
const ll INF = 1ll << 60;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    vector<vector<ll>> a(h, vector<ll>(w));
    for(int i = 0; i < h; ++i) for(int j = 0; j < w; ++j) cin >> a[i][j];
    
    vector<vector<ll>> ressum(h, vector<ll>(w, 0));
    queue<pair<int, int>> q;
    vector<vector<bool>> seen(h, vector<bool>(w, false));
    for(int si = 0; si < h; ++si) for(int sj = 0; sj < w; ++sj){
        q.push({si, sj});
        seen.assign(h, vector<bool>(w, false));
        seen[si][sj] = true;
        ressum[si][sj] = (ressum[si][sj] + 1) % mod;

        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();

            int y = p.first;
            int x = p.second;
            
            int cnt = 0;
            for(int dir = 0; dir < 4; ++dir){
                int ny = y + dy[dir];
                int nx = x + dx[dir];

                if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
                if(a[ny][nx] >= a[y][x]) continue;

                seen[ny][nx] = true;
                ressum[si][sj] = (ressum[si][sj] + 1) % mod;
                q.push({ny, nx});
                ++cnt;
            }

            if(cnt) seen[y][x] = false;
        }
    }

    ll res = 0;
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j) res = (res + ressum[i][j]) % mod;
    }

    cout << res << endl;

    return 0;
}
