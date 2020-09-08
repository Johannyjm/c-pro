#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int r, c, si, sj, gi, gj;
    cin >> r >> c >> si >> sj >> gi >> gj;
    --si; --sj; --gi; --gj;
    vector<string> grid(r);
    rep(i, r) cin >> grid[i];

    queue<P> q;

    const ll INF = 1001001001;
    vector<vector<int>> dist(r, vector<int>(c, INF));
    auto update = [&](int i, int j, int x){
        if(dist[i][j] != INF) return;
        dist[i][j] = x;
        q.push(P(i, j));
    };

    update(si, sj, 0);
    int di[] = {-1, 0, 1, 0};
    int dj[] = {0, -1, 0, 1};

    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        rep(dir, 4){
            int ni = i + di[dir];
            int nj = j + dj[dir];

            if(ni<0 || ni>=r || nj<0 || nj>=c) continue;
            if(grid[ni][nj] == '#') continue;

            update(ni, nj, dist[i][j]+1);
        }

    }

    cout << dist[gi][gj] << endl;

    return 0;
}