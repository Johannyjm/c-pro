#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i, h) cin >> a[i];

    vector<vector<int>> cnt(h, vector<int>(w, -1));
    queue<pair<int, int>> q;
    rep(i, h) rep(j, w){
        if(a[i][j]=='#'){
            cnt[i][j] = 0;
            q.push({i, j});
        }
    }

    int res = 0;
    while(!q.empty()){
        pair<int, int> p = q.front();
        q.pop();

        int y = p.first;
        int x = p.second;

        rep(dir, 4){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
            if(cnt[ny][nx] != -1) continue;

            cnt[ny][nx] = cnt[y][x] + 1;
            q.push({ny, nx});

            res = max(res, cnt[ny][nx]);
        }
    }


    cout << res << endl;

    return 0;
}