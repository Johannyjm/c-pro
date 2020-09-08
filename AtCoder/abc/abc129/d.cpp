#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];

    vector<vector<pair<char, int>>> wcnt(h);
    rep(i, h){
        vector<pair<char, int>> c;
        c.push_back(make_pair(s[i][0], 1));
        rep1(j, w){
            if(s[i][j] == c.back().first) ++c.back().second;
            else c.push_back(make_pair(s[i][j], 1));
        }
        wcnt[i] = c;
    }

    vector<vector<pair<char, int>>> hcnt(w);
    rep(i, w){
        vector<pair<char, int>> c;
        c.push_back(make_pair(s[0][i], 1));
        rep1(j, h){
            if(s[j][i] == c.back().first) ++c.back().second;
            else c.push_back(make_pair(s[j][i], 1));
        }
        hcnt[i] = c;
    }

    vector<vector<int>> wmap(h, vector<int>(w, -1));
    rep(i, h){
        int ptr = 0;
        rep(j, wcnt[i].size()){
            int val = -1;
            if(wcnt[i][j].first == '.') val = wcnt[i][j].second;
            for(int k = ptr; k < ptr+wcnt[i][j].second; ++k) wmap[i][k] = val;
            ptr += wcnt[i][j].second;
        }
    }

    vector<vector<int>> hmap(h, vector<int>(w, -1));
    rep(i, w){
        int ptr = 0;
        rep(j, hcnt[i].size()){
            int val = -1;
            if(hcnt[i][j].first == '.') val = hcnt[i][j].second;
            for(int k = ptr; k < ptr+hcnt[i][j].second; ++k) hmap[k][i] = val;
            ptr += hcnt[i][j].second;
        }
    }

    int res = 0;
    rep(i, h) rep(j, w){
        if(wmap[i][j] == -1 || hmap[i][j] == -1) continue;
        res = max(res, wmap[i][j] + hmap[i][j] - 1);
    }

    cout << res << endl;

    return 0;
}