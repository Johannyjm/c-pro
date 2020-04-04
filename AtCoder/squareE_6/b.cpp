#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    ll res = 1LL << 60;
    rep(i, n){
        rep(j, n){
            ll s = a[i];
            ll g = b[j];
            if(s > g) continue;

            ll cost = 0;
            rep(k, n){

                ll l = a[k];
                ll r = b[k];

                if(s<=l && r<=g) cost += g-s;
                else if(l<=s && r<=g) cost += (s-l) * 2 + g-s;
                else if(s<=l && g<=r) cost += r-s + r-g;
                else if(l<=s && g<=r) cost += (s-l) * 2 + (r-g) * 2 + g-s;

            }
            // cout << cost << " " << s << " " << g << endl;
            res = min(res, cost);
        }
    }

    cout << res << endl;

    return 0;
}