#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w, k;
    cin >> h >> w >> k;

    vector<string> c(h);
    rep(i, h) cin >> c[i];


    int res = 0;
    rep(ih, 1<<h){
        rep(iw, 1<<w){
            vector<int> use_h(h, 0), use_w(w, 0);

            rep(j, h){
                if(ih & (1<<j)) use_h[j] = 1;
            }
            rep(j, w){
                if(iw & (1<<j)) use_w[j] = 1;
            }

            int cnt = 0;
            rep(i, h) rep(j, w){
                if(use_h[i] == 1 || use_w[j] == 1) continue;
                if(c[i][j] == '.') continue;

                ++cnt;
            }

            if(cnt == k) ++res;
        }
    }

    cout << res << endl;

    return 0;
}