#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int n, m;
vector<int> a;
vector<int> cnt;
vector<vector<int>> change;
vector<vector<int>> dp;

int solve(int s, int d, int v){

    if(dp[s][v] >= 0) return dp[s][v];

    int ret = change[v][d+cnt[v]] - change[v][d];

    if(s == (1<<m)-1) return dp[s][v] = ret;

    int tmp = INF;
    rep(nv, m){
        if(!(s & (1<<nv))){
            tmp = min(tmp, solve(s|(1<<nv), d+cnt[v], nv));
        }
    }
    ret += tmp;

    dp[s][v] = ret;

    return ret;

}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    a.resize(n);
    cnt.assign(m, 0);

    rep(i, n) {
        cin >> a[i];
        --a[i];
        ++cnt[a[i]];
    }

    change.assign(m, vector<int>(n+1, -10));
    rep(i, m){
        change[i][0] = 0;
    }
    rep(i, m){
        rep(j, n){
            change[i][j+1] = change[i][j] + (a[j] != i);
        }
    }
    
    dp.assign(1<<m, vector<int>(m, -1));

    int res = INF;
    rep(nv, m){
        res = min(res, solve(0|(1<<nv), 0, nv));
    }

    cout << res << endl;

    return 0;
}