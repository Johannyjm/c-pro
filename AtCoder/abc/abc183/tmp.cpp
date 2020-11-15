#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint1000000007;

ll h, w;
vector<string> s;
vector<vector<mint>> dp;

mint rec(int y, int x){
    if(dp[y][x] != -1) return dp[y][x];
    if(y == 0 && x == 0) return dp[y][x] = 1;

    mint ret = 0;
    int ny = y;
    while(ny > 0){
        --ny;
        if(s[ny][x] == '#') break;
        ret += rec(ny, x);
    }

    int nx = x;
    while(nx > 0){
        --nx;
        if(s[y][nx] == '#') break;
        ret += rec(y, nx);
    }

    int yy = y;
    int xx = x;
    while(yy>0 && xx>0){
        --yy;
        --xx;
        if(s[yy][xx] == '#') break;
        ret += rec(yy, xx);
    }

    return dp[y][x] = ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    // cin >> h >> w;
    h = w = 2000;
    string ww = "";
    rep(j, w) ww += '.';
    s.resize(h, ww);
    // rep(i, h) cin >> s[i];

    dp.resize(h, vector<mint>(w, -1));
    
    cout << rec(h-1, w-1).val() << endl;


    return 0;
}