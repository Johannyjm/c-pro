#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w, k;
    cin >> h >> w >> k;

    vector<string> a(h);
    rep(i, h) cin >> a[i];

    vector<vector<int>> res(h, vector<int>(w, 0));
    int cnt = 1;
    rep(i, h){
        int s_cnt = 0;
        rep(j, w) if(a[i][j] == '#') ++s_cnt;

        if(s_cnt == 1){
            rep(j, w) res[i][j] = cnt;
            ++cnt;
        }
        int l_cnt = 1;
        if(s_cnt > 1){
            rep(j, w){
                res[i][j] = cnt;

                if(a[i][j] == '#') {
                    if(cnt<k && l_cnt<s_cnt) {
                        ++cnt;
                        ++l_cnt;
                    }

                }
            }
            ++cnt;
        }
    }

    rep(i, h) rep(j, w){
        if(res[i][j] == 0){
            if(i==0) res[i][j] = res[i+1][j];
            else res[i][j] = res[i-1][j];
        }
    }

    for(int i = h-2; i >= 0; --i) rep(j, w){
        if(res[i][j] == 0){
            res[i][j] = res[i+1][j];
        }
    }

    rep(i, h){
        rep(j, w) cout << res[i][j] << " ";
        cout << endl;
    }

    return 0;
}