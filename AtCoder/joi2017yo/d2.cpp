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
vector<vector<vector<int>>> dp;

int solve(int s, int d, int v){
    
    if(dp[s][d][v] >= 0) return dp[s][d][v];

    int ret = 0;
    for(int i = d; i < d+cnt[v]; ++i){
        if(a[i] != v) ++ret;
    }

    if(s == (1<<m)-1) return ret;

    int tmp = INF;
    rep(nv, m){
        if(!(s & (1<<nv))){
            tmp = min(tmp, solve(s|(1<<nv), d+cnt[v], nv));
        }
    }
    ret += tmp;

    dp[s][d][v] = ret;

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
    
    dp.assign(1<<m, vector<vector<int>>(n, vector<int>(m, -1)));

    int res = INF;
    rep(nv, m){
        res = min(res, solve(0|(1<<nv), 0, nv));
    }

    cout << res << endl;

    return 0;
}