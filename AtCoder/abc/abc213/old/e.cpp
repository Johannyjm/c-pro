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

        rep(dir, 4){
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if(ny<0 || ny>=h || nx<0 || nx>=w) continue;

            int cost = 0;
            if(s[ny][nx] == '#') cost = 1;

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

    if(dist[h-1][w-1] == 0){
        cout << 0 << endl;
        return 0;
    }

    int res = 0;
    int st = dist[h-1][w-1];
    vector<vector<bool>> reachable(h, vector<bool>(w, false));
    reachable[h-1][w-1] = true;
    queue<pair<int, int>> q;
    q.push({h-1, w-1});
    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();
        int y = p.first;
        int x = p.second;

        rep(dir, 4){
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
            if(dist[ny][nx] != dist[y][x]) continue;
            if(reachable[ny][nx] == true) continue;
            reachable[ny][nx] = true;
            q.push({ny, nx});
        }
    }

    while(true){
        bool found = false;
        int cy = -1;
        int cx = 1;
        int mx, mn;

        for(int i = h-2; i >= 0; --i){
            for(int j = w-2; j >= 0; --j){
                mx = max({dist[i][j], dist[i+1][j], dist[i][j+1], dist[i+1][j+1]});
                mn = min({dist[i][j], dist[i+1][j], dist[i][j+1], dist[i+1][j+1]}); 

                if(mx != st) continue;

                bool valid = false;
                if(dist[i][j] == mn && s[i][j] == '#') valid = true;
                if(dist[i+1][j] == mn && s[i+1][j] == '#') valid = true;
                if(dist[i][j+1] == mn && s[i][j+1] == '#') valid = true;
                if(dist[i+1][j+1] == mn && s[i+1][j+1] == '#') valid = true;
                
                if(!valid) continue;

                bool valid2 = false;
                if(dist[i][j] == mx){
                    int ny = i - 1;
                    int nx = j;
                    if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
                    if(reachable[ny][nx]) valid2 = true;

                    ny = i;
                    nx = j - 1;
                    if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
                    if(reachable[ny][nx]) valid2 = true;
                }
                if(dist[i+1][j] == mx){
                    int ny = i + 2;
                    int nx = j;
                    if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
                    if(reachable[ny][nx]) valid2 = true;

                    ny = i + 1;
                    nx = j - 1;
                    if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
                    if(reachable[ny][nx]) valid2 = true;
                }
                if(dist[i][j+1] == mx){
                    int ny = i - 1;
                    int nx = j + 1;
                    if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
                    if(reachable[ny][nx]) valid2 = true;

                    ny = i;
                    nx = j + 2;
                    if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
                    if(reachable[ny][nx]) valid2 = true;
                }
                if(dist[i+1][j+1] == mx){
                    int ny = i + 2;
                    int nx = j + 1;
                    if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
                    if(reachable[ny][nx]) valid2 = true;

                    ny = i + 1;
                    nx = j + 2;
                    if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
                    if(reachable[ny][nx]) valid2 = true;
                }

                if(!valid2) continue;
                 
                cy = i;
                cx = j;

                if(mx - mn == 2){
                    found = true;
                    break;
                }

            }
            if(found) break;
        }

        // cout << st << " " << mx << " " << mn << endl;

        ++res;
        st = mn - 1;
        if(st <= 0) break;

        reachable[cy][cx] = true;
        reachable[cy+1][cx] = true;
        reachable[cy][cx+1] = true;
        reachable[cy+1][cx+1] = true;
         
        queue<pair<int, int>> q;
        q.push({cy, cx});
        q.push({cy+1, cx});
        q.push({cy, cx+1});
        q.push({cy+1, cx+1});
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            int y = p.first;
            int x = p.second;

            rep(dir, 4){
                int ny = y + dy[dir];
                int nx = x + dx[dir];

                if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
                if(dist[ny][nx] != dist[y][x]) continue;
                if(reachable[ny][nx] == true) continue;
                reachable[ny][nx] = true;
                q.push({ny, nx});
            }
        }

    }

    cout << res << endl;

    return 0;
}