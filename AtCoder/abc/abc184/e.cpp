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

struct Edge{
    int to;
    int weight;

    Edge(int t, int w): to(t), weight(w){}
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    vector<vector<Edge>> g(h*w + 26);
    int sy = -1;
    int sx = -1;
    int gy = -1;
    int gx = -1;
    rep(i, h) rep(j, w){
        if(s[i][j] == '#') continue;
        if(s[i][j] == 'S'){
            sy = i;
            sx = j;
        }
        if(s[i][j] == 'G'){
            gy = i;
            gx = j;
        }

        rep(dir, 4){
            int ny = i + dy[dir];
            int nx = j + dx[dir];

            if(ny<0||ny>=h||nx<0||nx>=w) continue;
            if(s[ny][nx] == '#') continue;

            g[g2f(i, j)].push_back(Edge(g2f(ny, nx), 1));
        }

        if('a'<=s[i][j] && s[i][j]<='z'){
            g[h*w + s[i][j]-'a'].push_back(Edge(g2f(i, j), 0));
            g[g2f(i, j)].push_back(Edge(h*w + s[i][j]-'a', 1));
        }
    }

    const int INF = 1001001001;
    vector<int> dist(h*w+26, INF);
    dist[g2f(sy, sx)] = 0;

    deque<int> dq;
    dq.push_back(g2f(sy, sx));

    while(!dq.empty()){
        int v = dq.front();
        dq.pop_front();

        for(auto ne: g[v]){
            if(dist[ne.to] <= dist[v]+ne.weight) continue;

            dist[ne.to] = dist[v] + ne.weight;
            
            if(ne.weight == 1) dq.push_back(ne.to);
            if(ne.weight == 0) dq.push_front(ne.to);
        }
    }

    int res = dist[g2f(gy, gx)];
    if(res == INF) res = -1;
    cout << res << endl;

    // rep(i, h*w+26){
    //     cout << dist[i] << " ";
    //     if(i%w==w-1) cout << endl;
    // }

    return 0;
}