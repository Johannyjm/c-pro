#include <iostream>
#include <vector>
#include <string>
using namespace std;

int h, w;
vector<string> s;
vector<vector<int>> dp;

int rec(int y, int x){
    if(dp[y][x] != -1) return dp[y][x];
    if(y<0 || y>=h || x<0 || x>=w || s[y][x]=='#') return dp[y][x] = 1;

    int ret = 0;
    if(rec(y+1, x) == 0) ret = 1;
    if(rec(y, x+1) == 0) ret = 1;
    if(rec(y+1, x+1) == 0) ret = 1;

    return dp[y][x] = ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> h >> w;

    s.resize(h);
    for(int i = 0; i < h; ++i) cin >> s[i];

    dp.resize(h+1, vector<int>(w+1, -1));
    if(rec(0, 0) == 1) cout << "First" << endl;
    else cout << "Second" << endl;

    return 0;
}
