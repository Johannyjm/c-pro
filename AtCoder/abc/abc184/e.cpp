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

    vector<vector<int>> g(h*w);
    int sy = -1;
    int sx = -1;
    int gy = -1;
    int gx = -1;
    vector<int> leader(26, -1);
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

            g[g2f(i, j)].push_back(g2f(ny, nx));
            g[g2f(ny, nx)].push_back(g2f(i, j));
        }

        if('a'<=s[i][j] && s[i][j]<='z'){
            if(leader[s[i][j]-'a'] == -1){
                leader[s[i][j]-'a'] = g2f(i, j);
            }
            else{
                g[leader[s[i][j]-'a']].push_back(g2f(i, j));
                g[g2f(i, j)].push_back(leader[s[i][j]-'a']);
            }
        }
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
            if(v==g2f(sy, sx)||nv==g2f(sy, sx)) cout << "v: " << v << ", nv: " << nv << " " << dist[nv] <<  endl;
            if(dist[nv] > dist[v] + 1){
                dist[nv] = dist[v] + 1;
                pq.push({dist[nv], nv});
            }
        }
    }
    int res = dist[g2f(gy, gx)];
    if(res == INF) res= -1;
    cout << res << endl;


    rep(i, h){
        rep(j, w){
            if(dist[i*h+j]==INF) cout << 'I' << " ";
            else cout << dist[i*h+j] << " ";
        }
        cout << endl;
    }

    return 0;
}