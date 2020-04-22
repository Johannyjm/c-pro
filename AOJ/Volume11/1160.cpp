#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

const int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};


int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    while(1){
        int w, h;
        cin >> w >> h;

        if(w==0) break;

        vector<vector<int>> c(h, vector<int>(w));
        rep(i, h) rep(j, w) cin >> c[i][j];

        int cnt = 0;
        vector<vector<int>> seen(h, vector<int>(w, 0));

        rep(i, h) rep(j, w){
            if(c[i][j] == 0) continue;
            if(seen[i][j]) continue;
            ++cnt;
            
            seen[i][j] = cnt;
            vector<pair<int, int>> stack;
            stack.push_back(make_pair(i, j));
            while(!stack.empty()){
                int x = stack.back().second;
                int y = stack.back().first;
                stack.pop_back();

                rep(dir, 8){
                    int ny = y + dy[dir];
                    int nx = x + dx[dir];

                    if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
                    if(c[ny][nx] == 0) continue;
                    if(seen[ny][nx] != 0) continue;

                    seen[ny][nx] = cnt;
                    stack.push_back(make_pair(ny, nx));
                }
            }
        }

        cout << cnt << endl;
    }

    return 0;
}