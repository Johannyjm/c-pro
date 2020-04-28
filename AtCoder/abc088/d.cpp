#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    const int INF = 1001001001;
    vector<vector<int>> dist(h, vector<int>(w, INF));
    dist[0][0] = 0;

    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        rep(dir, 4){
            int ni = i + di[dir];
            int nj = j + dj[dir];

            if(ni<0 || ni>=h || nj<0|| nj>=w) continue;
            if(s[ni][nj] == '#') continue;
            if(dist[ni][nj] != INF) continue;

            dist[ni][nj] = dist[i][j] + 1;
            q.push(make_pair(ni, nj));
        }
    }

    if(dist[h-1][w-1] == INF){
        cout << -1 << endl;
        return 0;
    }

    vector<vector<bool>> is_fixed(h, vector<bool>(w, false));
    is_fixed[0][0] = true;
    is_fixed[h-1][w-1] = true;
    int i = h-1;
    int j = w-1;
    while(!(i==0 && j==0)){
        rep(dir, 4){
            int ni = i + di[dir];
            int nj = j + dj[dir];

            if(ni<0 || ni>=h || nj<0|| nj>=w) continue;
            if(dist[ni][nj] == INF) continue;
            if(dist[ni][nj] != dist[i][j] - 1) continue;

            is_fixed[ni][nj] = true;
            i = ni;
            j = nj;
        }
    }

    int res = 0;
    rep(i, h) rep(j, w){
        if(!is_fixed[i][j] && s[i][j]=='.') ++res;
    }

    cout << res << endl;

    return 0;
}