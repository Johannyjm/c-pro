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

    vector<vector<int>> jsm(m, vector<int>(n, 0));
    vector<vector<int>> osm(m, vector<int>(n, 0));
    vector<vector<int>> ism(m, vector<int>(n, 0));
    if(c[0][0] == 'J') jsm[0][0] = 1;
    if(c[0][0] == 'O') osm[0][0] = 1;
    if(c[0][0] == 'I') ism[0][0] = 1;

    rep1(i, m){
        jsm[i][0] = jsm[i-1][0] + (c[i][0] == 'J');
        osm[i][0] = osm[i-1][0] + (c[i][0] == 'O');
        ism[i][0] = ism[i-1][0] + (c[i][0] == 'I');
    }
    
    rep1(j, n){
        jsm[0][j] = jsm[0][j-1] + (c[0][j] == 'J');
        osm[0][j] = osm[0][j-1] + (c[0][j] == 'O');
        ism[0][j] = ism[0][j-1] + (c[0][j] == 'I');
    }

    rep1(i, m) rep1(j, n){
        jsm[i][j] = jsm[i][j-1] + (jsm[i][j] == 'J');
        osm[i][j] = osm[i][j-1] + (osm[i][j] == 'O');
        ism[i][j] = ism[i][j-1] + (ism[i][j] == 'I');
    }

    rep1(i, m) rep1(j, n){
        jsm[i][j] += jsm[i-1][j];
        osm
    }

    rep(i, m){
        rep(j, n) cout << jsm[i][j] << " ";
        cout << endl;
    }


    return 0;
}