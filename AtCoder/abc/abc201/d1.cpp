#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int h, w;
int dp[2200][2200];
vector<string> a;
const int INF = 1001001001;

int rec(int i, int j){
    if(dp[i][j] != -INF) return dp[i][j];
    if(i == h-1 && j == w-1) return dp[h-1][w-1] = 0;

    int ret;
    int gain;
    if((i + j) % 2 == 0){ // Takahashi
        ret = -INF;
        if(i < h-1){
            if(a[i+1][j] == '+') gain = 1;
            else gain = -1;
            ret = max(ret, rec(i+1, j) + gain);
        }
        if(j < w-1){
            if(a[i][j+1] == '+') gain = 1;
            else gain = -1;
            ret = max(ret, rec(i, j+1) + gain);
        }

        return dp[i][j] = ret;
    }

    else{ // Aoki
        ret = INF;
        if(i < h-1){
            if(a[i+1][j] == '+') gain = -1;
            else gain = 1;
            ret = min(ret, rec(i+1, j) + gain);
        }
        if(j < w-1){
            if(a[i][j+1] == '+') gain = -1;
            else gain = 1;
            ret = min(ret, rec(i, j+1) + gain);
        }

        return dp[i][j] = ret;
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> h >> w;
    a.resize(h);
    rep(i, h) cin >> a[i];
    rep(i, h) rep(j, w) dp[i][j] = -INF;

    int res = rec(0, 0);
    if(res > 0) puts("Takahashi");
    else if(res < 0) puts("Aoki");
    else puts("Draw");

    return 0;
}