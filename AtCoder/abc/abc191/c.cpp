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
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    vector<vector<int>> state(h, vector<int>(w, 1));
    int res = 0;
    rep(i, h) rep(j, w){
        if(s[i][j] == '.') continue;

        rep(dir, 4){
            int ny = i + dy[dir];
            int nx = j + dx[dir];
            if(s[ny][nx] == '#') continue;

            if(dir == 0){
                if(state[i-1][j] % 2 == 0){
                    state[i][j] *= 2;
                    continue;
                }
                ++res;
                state[i][j] *= 2;
            }
            if(dir == 1){
                if(state[i][j-1] % 3 == 0){
                    state[i][j] *= 3;
                    continue;
                }
                ++res;
                state[i][j] *= 3;
            }
            if(dir == 2){
                if(state[i-1][j] % 5 == 0){
                    state[i][j] *= 5;
                    continue;
                }
                ++res;
                state[i][j] *= 5;
            }
            if(dir == 3){
                if(state[i][j-1] % 7 == 0){
                    state[i][j] *= 7;
                    continue;
                }
                ++res;
                state[i][j] *= 7;
            }
        }
    }

    cout << res << endl;

    return 0;
}