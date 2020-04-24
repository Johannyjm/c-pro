#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

const int dj[] = {1, 0, -1, 0};
const int di[] = {0, 1, 0, -1};

int w, h;
vector<vector<int>> s;

int dfs(int i, int j, int cnt, vector<vector<bool>> seen){
    int ret = 0;
    seen[i][j] = true;

    bool is_edge = true;
    rep(dir, 4){
        int ni = i + di[dir];
        int nj = j + dj[dir];

        if(ni<0 || ni>=h || nj<0|| nj>=w) continue;
        if(s[ni][nj] == 0) continue;
        if(seen[ni][nj]) continue;

        is_edge = false;
        int sum_cnt = dfs(ni, nj, cnt+1, seen);
        ret = max({ret, cnt, sum_cnt});
    }

    if(is_edge) ret = cnt;
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> w >> h;

    s.resize(h, vector<int>(w));
    rep(i, h) rep(j, w) cin >> s[i][j];

    int res = 0;
    rep(i, h) rep(j, w) {
        if(s[i][j] == 0) continue;

        vector<vector<bool>> seen(h, vector<bool>(w, false));
        int cnt = 0;
        cnt = dfs(i, j, 1, seen);
        
        res = max(res, cnt);
    }

    cout << res << endl;

    return 0;
}