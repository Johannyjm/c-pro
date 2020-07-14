#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, q;
    cin >> n >> q;
    vector<ll> a(n), x(q);
    rep(i, n) cin >> a[i];
    rep(i, q) cin >> x[i];

    rep(i, q){
        ll r = 0;
        ll sm = a[0];
        ll res = 0;
        for(ll l = 0; l < n; ++l){
            if(l > 0) sm -= a[l-1];
            while(r < n && sm <= x[i]){
                ++r;
                sm += a[r];
            }

            res += r-l;
        }

        cout << res << endl;
    }

    return 0;
}