#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    const int dx[] = {1, 0, -1, 0};
    const int dy[] = {0, 1, 0, -1};
    const int inf = -1;

    int h, w;
    cin >> h >> w;

    vector<string> c(h);
    rep(i, h) cin >> c[i];

    vector<pair<int, int>> stack;
    vector<vector<int>> dist(h, vector<int>(w, inf));
    rep(i, h) rep(j, w) {
        if(c[i][j] == 's'){
            stack.push_back(make_pair(i, j));
            dist[i][j] = 0;
            break;
        }
    }


    while(!stack.empty()){
        int x = stack.back().second;
        int y = stack.back().first;
        stack.pop_back();

        rep(dir, 4){
            int di = y + dy[dir];
            int dj = x + dx[dir];

            if(di<0 || di>=h || dj<0 || dj>=w) continue;
            if(c[di][dj] == '#') continue;
            if(dist[di][dj] != inf) continue;
            
            if(c[di][dj] == 'g'){
                // rep(i, h){
                //     rep(j, w) cout << dist[i][j];
                //     cout << endl;
                // }
                cout << "Yes" << endl;
                return 0;
            }
            if(c[di][dj] == '.') {
                stack.push_back(make_pair(di, dj));
                dist[di][dj] = dist[y][x] + 1;
            }
        }
    }

    // rep(i, h){
    //     rep(j, w) cout << dist[i][j];
    //     cout << endl;
    // }
    cout << "No" << endl;


    return 0;
}