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

    vector<int> a(m), b(m), x(m);
    rep(i, m){
        cin >> a[i] >> b[i] >> x[i];
        --a[i], --b[i];
    }

    vector<vector<int>> imosfr(n+1, vector<int>(n+1, 0));
    rep(i, m){
        int col = b[i];
        int from = a[i];
        int to = a[i] + x[i];

        ++imosfr[from][col];
        --imosfr[to+1][col];
    }

    rep(col, n+1) rep1(row, n+1) imosfr[row][col] += imosfr[row-1][col];


    vector<vector<int>> imosto(n+1, vector<int>(n+1, 0));
    rep(i, m){
        int colfr = b[i] + 1;
        int colto = colfr + x[i] + 1;
        int from = a[i];
        int to = a[i] + x[i] + 1;

        --imosto[from][colfr];
        ++imosto[to][colto];
    }

    rep1(i, n+1){
        rep1(j, n+1){
            imosto[i][j] += imosto[i-1][j-1];
        }
    }

    vector<vector<int>> imos(n+1, vector<int>(n+1, 0));
    rep(i, n+1) rep(j, n+1) imos[i][j] = imosfr[i][j] + imosto[i][j];
    rep(row, n+1) rep1(col, n+1) imos[row][col] += imos[row][col-1];

    int res = 0;
    rep(i, n+1) rep(j, n+1){
        if(imos[i][j] > 0) ++res;
    }

    cout << res << endl;

    return 0;
}