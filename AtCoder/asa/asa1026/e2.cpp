#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];

    ll res = 0;
    rep(l, n+1) rep(r, n+1){
        if(l+r > n || l+r > k) continue;
        int remain = k-l-r;
        remain = min(remain, l+r);
        ll sm = 0;
        vector<ll> use;
        rep(i, l){
            sm += v[i];
            use.push_back(v[i]);
        }
        rep(i, r){
            sm += v[n-i-1];
            use.push_back(v[n-i-1]);
        }

        sort(use.begin(), use.end());
        
        ll sub = 0;
        ll subsum = sm;
        // cout << sm << endl;
        res = max(res, sm);

        rep(j, remain){
            sub += use[j];
            subsum = max(subsum, sm-sub);
        }

        // sm -= sub;
        // cout << l << " " << r << " " << remain << " " << sm << " " << subsum << endl;
        res = max(res, subsum);
    }

    cout << res << endl;

    return 0;
}