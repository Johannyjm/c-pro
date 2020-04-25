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

    int h, w, n;
    cin >> h >> w >> n;

    vector<string> grid(h);
    rep(i, h) cin >> grid[i];

    pair<int, int> start;
    vector<pair<int, int>> goals(n); 
    rep(i, h) rep(j, w){
        if(grid[i][j] == 'S') start = make_pair(i, j);
        else if(grid[i][j]!='X' && grid[i][j]!='.'){
            int idx = grid[i][j] - '0';
            --idx;
            goals[idx] = make_pair(i, j);
        }
    }

    // cout << start.first << " " << start.second << endl;
    // cout << endl;
    // rep(i, n) {
    //     cout << goals[i].first << " " << goals[i].second << endl;
    // }

    int res = 0;
    rep(i, n){
        int si = start.first;
        int sj = start.second;
        int gi = goals[i].first;
        int gj = goals[i].second;

        queue<pair<int, int>> q;
        q.push(start);
        vector<vector<int>> dist(h, vector<int>(w, -1));
        dist[si][sj] = 0;
        while(!q.empty()){
            int ci = q.front().first;
            int cj = q.front().second;
            q.pop();

            rep(dir, 4){
                int ni = ci + dy[dir];
                int nj = cj + dx[dir];

                if(ni<0 || ni>=h || nj<0|| nj>=w) continue;
                if(grid[ni][nj] == 'X') continue;
                if(dist[ni][nj] != -1) continue;

                dist[ni][nj] = dist[ci][cj] + 1;
                q.push(make_pair(ni, nj));
            }
        }

        // rep(j, h){
        //     rep(k, w) cout << dist[j][k];
        //     cout << endl;
        // }

        start = goals[i];
        res += dist[gi][gj];
    }

    cout << res << endl;

    return 0;
}