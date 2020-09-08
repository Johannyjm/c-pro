#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int h, w;
vector<string> c;
bool flg = false;
vector<vector<bool>> seen;

void dfs(int y, int x){
    seen[y][x] = true;

    rep(dir, 4){
        int di = y + dy[dir];
        int dj = x + dx[dir];

        if(di<0 || di>=h || dj<0 || dj>=w) continue;
        if(c[di][dj] == '#') continue;
        if(seen[di][dj]) continue;

        if(c[di][dj] == 'g'){
            flg = true;
            return;
        }

        dfs(di, dj);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> h >> w;
    
    c.resize(h);
    rep(i, h) cin >> c[i];

    seen.assign(h, vector<bool>(w, false));

    int sx, sy;
    rep(i, h) rep(j, w) {
        if(c[i][j] == 's'){
            sx = j;
            sy = i;
            seen[i][j] = true;
            break;
        }
    }

    dfs(sy, sx);

    if(flg) puts("Yes");
    else puts("No");

    return 0;
}