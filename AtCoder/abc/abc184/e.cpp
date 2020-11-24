#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int h, w;
int g2f(int y, int x){
    return y*w + x;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    int sy, sx, gy, gx;
    vector<vector<int>> g(h*w);
    vector<vector<pair<int, int>>> warp(26);
    rep(i, h) rep(j, w){
        if(s[i][j] == '#') continue;
        if(s[i][j] == 'S'){
            sy = i;
            sx = j;
        }
        else if(s[i][j] == 'G'){
            gy = i;
            gx = j;
        }

        else if('a'<=s[i][j] && s[i][j]<='z'){
            warp[s[i][j] - 'a'].push_back({i, j});
        }

        rep(dir, 4){
            int ny = i + dy[dir];
            int nx = j + dx[dir];

            if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
            if(s[ny][nx] == '#') continue;
            // cout << i << " " << j << " " << ny << " " << nx << endl;
            g[g2f(i, j)].push_back(g2f(ny, nx));
            g[g2f(ny, nx)].push_back(g2f(i, j));
        }
    }

    rep(i, 26){
        if(warp[i].size() == 0) continue;
        int y0 = warp[i][0].first;
        int x0 = warp[i][0].second;
        int y1 = warp[i][1].first;
        int x1 = warp[i][1].second;

        g[g2f(y0, x0)].push_back(g2f(y1, x1));
        g[g2f(y1, x1)].push_back(g2f(y0, x0));
    }

    const int INF = 1001001001;
    vector<int> dist(h*w, INF);
    dist[g2f(sy, sx)] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, g2f(sy, sx)});

    while(!pq.empty()){
        pair<int, int> p = pq.top();
        int v = p.second;
        pq.pop();

        for(auto nv: g[v]){
            // cout << "v: " << v << ", nv: " << nv << endl;
            if(dist[nv] > dist[v] + 1){
                dist[nv] = dist[v] + 1;
                pq.push({dist[nv], nv});
            }
        }
    }
    int res = dist[g2f(gy, gx)];
    if(res == INF) res= -1;
    cout << res << endl;
    // rep(i, h){
    //     rep(j, w) cout << dist[g2f(i, j)] << " ";
    //     cout << endl;
    // }

    return 0;
}