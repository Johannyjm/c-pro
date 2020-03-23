#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const int inf = 1<<9;

int h, w;
vector<string> c;
// vector<pair<int, int>> stack;
vector<vector<int>> dist;

bool dfs(int x, int y){
    rep(dir, 4){
    int di = y + dy[dir];
    int dj = x + dx[dir];

    if(di<0 || di>=h || dj<0 || dj>=w) continue;
    if(c[di][dj] == '#') continue;
    if(dist[di][dj] != inf) continue;
    
    if(c[di][dj] == 'g'){
        return true;
    }
    if(c[di][dj] == '.') {
        dist[di][dj] = dist[y][x] + 1;
        bool flg = dfs(dj, di);
        if(flg) return true;
    }
    return false;
}
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> h >> w;

    c.resize(h);
    rep(i, h) cin >> c[i];

    dist.resize(h, vector<int>(w, inf));

    int x, y;
    rep(i, h) rep(j, w) {
        if(c[i][j] == 's'){
            // stack.push_back(make_pair(i, j));
            dist[i][j] = 0;
            x = j;
            y = i;
            break;
        }
    }

    if(dfs(x, y)) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}