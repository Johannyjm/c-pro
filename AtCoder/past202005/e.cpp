#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> g(n);
    rep(_, m){
        int u, v;
        cin >> u >> v;
        --u;
        --v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> color(n);
    rep(i, n) cin >> color[i];

    rep(_, q){
        int cmd;
        cin >> cmd;

        if(cmd == 1){
            int x;
            cin >> x;
            --x;
            cout << color[x] << endl;
            for(int nv: g[x]){
                color[nv] = color[x];
            }
        }

        else{
            int y, z;
            cin >> y >> z;
            --y;
            cout << color[y] << endl;

            color[y] = z;
        }
    }

    return 0;
}