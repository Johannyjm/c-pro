#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int n, m;
vector<ll> a, b;
vector<vector<ll>> c;

ll dp[5500];
int seen[1100];
ll rec(ll s){
    // cout << s << endl;
    if(dp[s] != 0) return dp[s];
    if(s == (1<<n)-1) return 0;

    ll ret = 1001001001;
    for(int i = 0; i < m; ++i){
        bool flg = false;
        ll nxt = 0;
        for(auto j: c[i]){
            nxt += 1<<j;
            if((s & (1<<j)) == 0) flg = true;
        }
        // cout << i << " " << flg << " " << nxt << endl;

        if(flg){
            ret = min(ret, rec(s | nxt) + a[i]);
        }
    }

    return dp[s] = ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    a.resize(m);
    b.resize(m);
    c.resize(m);

    vector<int> cnt(n, 0);
    rep(i, m){
        cin >> a[i] >> b[i];
        rep(j, b[i]){
            int c_;
            cin >> c_;
            --c_;
            c[i].push_back(c_);
            ++cnt[c_];
        }
    }

    for(auto e: cnt){
        if(e == 0){
            cout << -1 << endl;
            return 0;
        }
    }

    cout << rec(0) << endl;

    return 0;
}