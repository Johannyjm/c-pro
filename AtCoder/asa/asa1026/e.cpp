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
    rep(i, k){ // i: no use
        rep(l, k+1){ // l: use from left
            if(i+l > k) continue;
            if(l > n) continue;

            int r = k-i-l;
            int remain = i;
            ll sm = 0;
            vector<ll> use;
            rep(j, l){
                sm += v[j];
                use.push_back(v[j]);
            }
            rep(j, r){
                sm += v[n-j-1];
                use.push_back(v[n-j-1]);
            }

            sort(use.begin(), use.end());
            
            ll sub = 0;
            remain = min(remain, (int)use.size());
            rep(j, remain) sub += use[j];

            sm -= sub;
            // cout << i << " " << l << " " << r << " " << remain << " " << use.size() << " " << sub << " " << sm << endl;
            res = max(res, sm);
        }

    }

    cout << res << endl;

    return 0;
}