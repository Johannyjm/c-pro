#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int n;
vector<vector<ll>> a;
vector<bool> seen;
ll res;
void dfs(ll now, vector<bool> seen){

    int cnt = 0;
    rep(i, 2*n){
        if(seen[i]) ++cnt;
    }

    if(cnt == 2*n){
        res = max(res, now);
        return;
    }

    int one = -1;
    rep(i, 2*n){
        if(seen[i]) continue;
        one = i;
        break;
    }

    seen[one] = true;
    rep(two, 2*n){
        if(seen[two]) continue;
        if(two <= one) continue;

        vector<bool> tmp = seen;
        tmp[two] = true;
        dfs(now ^ a[one][two], tmp);
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    a.resize(2*n, vector<ll>(2*n, -1));
    rep(i, 2*n-1){
        for(int j = i+1; j < 2*n; ++j) cin >> a[i][j];
    }

    res = 0;
    seen.resize(2*n, false);
    dfs(0, seen);

    cout << res << endl;

    return 0;
}