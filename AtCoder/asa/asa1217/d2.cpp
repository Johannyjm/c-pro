#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int h, w;
vector<pair<int, int>> bl;
int calc_dist(int i, int j){
    int ret = 1001001001;
    for(auto p: bl){
        int d = abs(i-p.first) + abs(j-p.second);
        ret = min(ret, d);
    }

    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i, h) cin >> a[i];

    vector<pair<int, int>> wh;
    rep(i, h) rep(j, w){
        if(a[i][j] == '#') bl.push_back({i, j});
        else wh.push_back({i, j});
    }

    int res = 0;
    for(auto p: wh){
        res = max(res, calc_dist(p.first, p.second));
    }

    cout << res << endl;



    return 0;
}