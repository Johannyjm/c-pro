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
    vector<int> a(n), b(n), c(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];

    vector<vector<int>> idx(n+10);
    rep(i, n){
        idx[b[i]].push_back(i);
    }

    unordered_map<int, int> cnt;
    rep(i, n){
        ++cnt[c[i]];
    }

    vector<int> memo(n+10, -1);
    ll res = 0;
    rep(i, n){
        if(memo[a[i]] > 0){
            res += memo[a[i]];
            continue;
        }

        ll sm = 0;
        for(int ind: idx[a[i]]){
            sm += cnt[ind+1];
        }
        memo[a[i]] = sm;

        res += sm;
    }

    cout << res << endl;

    return 0;
}