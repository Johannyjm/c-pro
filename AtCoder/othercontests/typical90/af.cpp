#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> a[i][j];
    int m;
    cin >> m;
    vector<vector<bool>> ng(n, vector<bool>(n, false));
    rep(i, m){
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        ng[x][y] = true;
        ng[y][x] = true;
    }

    vector<int>range(n);
    rep(i, n) range[i] = i;

    const int INF = 1001001001;
    int res = INF;

    do{
        int sm = a[range.front()][0];
        rep1(i, n){
            if(ng[range[i-1]][range[i]]) sm += INF;
            sm += a[range[i]][i];
        }

        res = min(res, sm);
    } while(next_permutation(range.begin(), range.end()));

    if(res == INF) res = -1;
    cout << res << endl;

    return 0;
}