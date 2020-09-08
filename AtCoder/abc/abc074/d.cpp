#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n)), dist(n, vector<int>(n));
    rep(i, n) rep(j, n){
        cin >> a[i][j];
        dist[i][j] = a[i][j];
    }

    rep(k, n) rep(i, n) rep(j, n){
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }

    rep(i, n) rep(j, n){
        if(dist[i][j] != a[i][j]){
            cout << -1 << endl;
            return 0;   
        }
    }

    const int no_conn = -1;
    rep(k, n) rep(i, n) rep(j, n){
        if(k==i || k==j) continue;

        if(a[i][j] == a[i][k] + a[k][j]) dist[i][j] = no_conn;
    }

    ll res = 0;
    rep(i, n) rep(j, n){
        if(i <= j || dist[i][j] == no_conn) continue;
        res += dist[i][j];
    }

    cout << res << endl;


    return 0;
}