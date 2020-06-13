#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int m, n, k;
    cin >> m >> n >> k;

    vector<vector<char>> c(m, vector<char>(n));
    rep(i, m) rep(j, n) cin >> c[i][j];

    vector<char> joi = {'J', 'O', 'I'};
    vector<vector<vector<int>>> sm(3, vector<vector<int>>(m, vector<int>(n, 0)));

    rep(i, m){
        rep(l, 3){
            if(c[i][0] == joi[l]) sm[l][i][0] = 1;
        }
    }
    
    rep(i, m) rep1(j, n) rep(l, 3){
        sm[l][i][j] = sm[l][i][j-1] + (c[i][j] == joi[l]);
    }

    rep1(i, m) rep(j, n) rep(l, 3){
        sm[l][i][j] += sm[l][i-1][j];
    }

    rep(_, k){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        --a;
        --b;
        --c;
        --d;

        vector<int> res(3);
        rep(l, 3){
            // calc w - x - y + z;
            int w = sm[l][c][d];
            int x = 0;
            int y = 0;
            int z = 0;
            if(a != 0) x = sm[l][a-1][d];
            if(b != 0) y = sm[l][c][b-1];
            if(a != 0 && b != 0) z = sm[l][a-1][b-1];

            res[l] = w - x - y + z;
        }
        
        cout << res[0] << " " << res[1] << " " << res[2] << "\n";
    }


    return 0;
}