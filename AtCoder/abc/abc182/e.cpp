#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w, n, m;
    cin >> h >> w >> n >> m;
    vector<int> a(n), b(n), c(m), d(m);
    vector<vector<int>> g(h, vector<int>(w, 0));
    rep(i, n){
        cin >> a[i] >> b[i];
        --a[i];
        --b[i];
        g[a[i]][b[i]] = 1;
    }
    rep(i, m){
        cin >> c[i] >> d[i];
        --c[i];
        --d[i];
        g[c[i]][d[i]] = -1;
    }

    vector<vector<int>> gh, gv;
    // horizontal;
    gh = g;
    rep(i, h){
        rep(j, w-1){
            if(gh[i][j]==-1 || gh[i][j+1]==-1) continue;
            gh[i][j+1] += gh[i][j];
        }
        for(int j = w-1; j >= 1; --j){
            if(gh[i][j]==-1 || gh[i][j-1]==-1) continue;
            gh[i][j-1] += gh[i][j];
        }
    }

    // vertical;
    gv = g;
    rep(j, w){
        rep(i, h-1){
            if(gv[i][j]==-1 || gv[i+1][j]==-1) continue;
            gv[i+1][j] += gv[i][j];
        }
        for(int i = h-1; i >= 1; --i){
            if(gv[i][j]==-1 || gv[i-1][j]==-1) continue;
            gv[i-1][j] += gv[i][j];
        }
    }

    // rep(i, h){
    //     rep(j, w) cout << g[i][j] << " ";
    //     cout << endl;
    // }

    int res = 0;
    rep(i, h){
        rep(j, w){
            if(gh[i][j]+gv[i][j] > 0) ++res;
        }
    }

    cout << res << endl;


    return 0;
}