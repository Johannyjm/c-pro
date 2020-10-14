#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> x(m), y(m);
    vector<vector<int>> relation(n, vector<int>(n, 0));
    rep(i, m){
        cin >> x[i] >> y[i];
        relation[x[i]-1][y[i]-1] = 1;
        relation[y[i]-1][x[i]-1] = 1;

    }

    int res = 0;
    rep(i, (1<<n)){
        vector<int> use(n, 0);
        int cnt = 0;
        rep(j, n){
            if(i & (1<<j)){
                use[j] = 1;
                ++cnt;
            }
        }

        bool flg = true;
        rep(a, n) rep(b, n){
            if(a <= b) continue;
            if(use[a]==0 || use[b]==0) continue;

            if(relation[a][b] == 0) flg = false;
        }

        if(flg) res = max(res, cnt);

    }

    cout << res << endl;

    return 0;
}