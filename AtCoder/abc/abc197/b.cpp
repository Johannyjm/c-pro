#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w, y, x;
    cin >> h >> w >> y >> x;

    vector<string> s(h);
    rep(i, h) cin >> s[i];

    --x;
    --y;
    int res = 1;
    const int dy[] = {0, 1, 0, -1};
    const int dx[] = {1, 0, -1, 0};

    rep(dir, 4){
        int cnt = 1;
        while(1){
            int ny = y + dy[dir] * cnt;
            int nx = x + dx[dir] * cnt;
            // cout << dir << " " << ny << " " << nx << endl;
            if(ny<0 || ny>=h || nx<0 || nx>=w) break;
            if(s[ny][nx] == '#') break;
            ++cnt;
        }
        res += cnt-1;
    }

    cout << res << endl;

    return 0;
}