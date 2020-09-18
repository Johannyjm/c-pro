#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

const int mod = 1000000007;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int h, w;
vector<vector<ll>> a, dp;
ll rec(int y, int x){
    if(dp[y][x] > 0) return dp[y][x];

    ll ret = 1;
    for(int dir = 0; dir < 4; ++dir){
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if(ny<0 || ny>=h || nx<0 || nx>=w) continue;
        if(a[ny][nx] <= a[y][x]) continue;

        ret = (ret + rec(ny, nx)) % mod;
    }

    return dp[y][x] = ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> h >> w;
    a.resize(h, vector<ll>(w));
    for(int i = 0; i < h; ++i) for(int j = 0; j < w; ++j) cin >> a[i][j];
    
    dp.resize(h, vector<ll>(w, 0));

    ll res = 0;
    for(int si = 0; si < h; ++si) for(int sj = 0; sj < w; ++sj){
        res = (res + rec(si, sj)) % mod;
    }

    cout << res << endl;

    return 0;
}
