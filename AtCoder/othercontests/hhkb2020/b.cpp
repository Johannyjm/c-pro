#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    rep(i, h) cin >> s[i];

    int res = 0;
    vector<vector<bool>> seen(h, vector<bool>(w, false));
    rep(i, h) rep(j, w){
        if(s[i][j] == '#') continue;
        seen[i][j] = true;

        rep(dir, 4){
            int ny = i + dy[dir];
            int nx = j + dx[dir];

            if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
            if(seen[ny][nx]) continue;

            if(s[ny][nx] == '.') ++res;
        }
    }

    cout << res << endl;

    return 0;
}