#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m, x;
    cin >> n >> m >> x;

    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, n){
        cin >> c[i];
        rep(j, m) cin >> a[i][j];
    }

    const int INF = 1001001001;
    int res = INF;
    rep(i, 1<<n){
        vector<bool> use(n, false);
        int cost = 0;
        rep(j, n){
            if(i & (1<<j)) {
                use[j] = true;
                cost += c[j];
            }
        }

        vector<int> learned(m, 0);
        rep(j, n){
            if(use[j]){
                rep(k, m) learned[k] += a[j][k];
            }
        } 

        bool flg = true;
        rep(j, m){
            if(learned[j] < x) {
                flg = false;
                break;
            }
        }

        if(flg) res = min(res, cost);

    }

    if(res == INF) cout << -1 << endl;
    else cout << res << endl;

    return 0;
}