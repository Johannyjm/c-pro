#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int w, h;
    cin >> w >> h;

    vector<vector<int>> s(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> s[i][j];

    int res = 0;
    rep(i, h) rep(j, w){

        if(s[i][j] == 0) continue;

        int num = 0;
        vector<vector<int>> broke(h, vector<int>(w, -1));

        vector<pair<int, int>> stack;
        stack.push_back(make_pair(i, j));
        broke[i][j] = 1;

        while(!stack.empty()){
            int y = stack.back().first;
            int x = stack.back().second;
            stack.pop_back();

            rep(dir, 4){
                int ny = y + dy[dir];
                int nx = x + dx[dir];

                if(ny<0 || ny>=h || nx<0|| nx>=w) continue;
                if(s[ny][nx] == 0) continue;
                if(broke[ny][nx] != -1) continue;

                broke[ny][nx] = broke[y][x] + 1;
                stack.push_back(make_pair(ny, nx));
                num = max(num, broke[ny][nx]);
            }

        }
        // cout << endl;
        // rep(k, h) {
        //     rep(l, w) cout << broke[k][l] << " ";
        //     cout << endl;
        // }

        res = max(res, num);
    }

    cout << res << endl;

    return 0;
}