#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w, d;
    cin >> h >> w >> d;
    vector<vector<int>> a(h, vector<int>(w));
    vector<pair<int, int>> cor(h*w);

    rep(i, h) rep(j, w){
        cin >> a[i][j];
        --a[i][j];
        cor[a[i][j]] = {i, j};
    }

    vector<vector<int>> sm(d);
    rep(start, d){
        sm[start].push_back(0);
        for(int idx = start; idx < h*w; idx += d){
            int from = idx;
            int to = from+d;
            if(to >= h*w) continue;

            int dist = abs(cor[from].first-cor[to].first) + abs(cor[from].second-cor[to].second);
            sm[start].push_back(sm[start].back()+dist);
        }
    }

    // rep(i, d){
    //     for(auto e: sm[i]) cout << e << " ";
    //     cout << endl;
    // }

    int q;
    cin >> q;

    // int res = 0;
    rep(_, q){
        int l, r;
        cin >> l >> r;
        --l;
        --r;

        int mod = l%d;
        int start = (l-mod)/d;
        int width = (r-l)/d;
        // cout << mod << " " << start << " " << width << endl;
        cout << sm[mod][start+width] - sm[mod][start] << "\n";
    }

    // cout << res << endl;

    return 0;
}