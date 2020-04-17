#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

ll calc_dist(ll d, ll x, ll y){
    return min(abs(x-y), d-abs(x-y));
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll d, n, m;
    cin >> d >> n >> m;
    vector<ll> s(n), k(m);
    
    s[0] = 0;
    rep(i, n-1) cin >> s[i];
    rep(i, m) cin >> k[i];

    sort(s.begin(), s.end());

    ll res = 0;
    rep(i, m){
        ll target = k[i];
        ll dist = 1001001001;

        ll l = 0;
        ll r = n-1;

        dist = min(dist, calc_dist(d, target, s[l]));
        dist = min(dist, calc_dist(d, target, s[r]));

        if(s[l]==target || s[r]==target){
            continue;
        }

        bool same = false;
        while(abs(r-l) > 1){
            ll m = (l + r) / 2;

            if(s[m]==target){
                same = true;
                break;
            }

            if(s[m] < target) l = m;
            else r = m;

            dist = min(dist, calc_dist(d, target, s[m]));
        }

        if(!same) res += dist;
    }

    cout << res << endl;


    return 0;
}