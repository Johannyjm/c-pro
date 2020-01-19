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

    pair<ll, ll> xl[n];
    rep(i, n) {
        ll x, l;
        cin >> x >> l;

        xl[i] = make_pair(x, l);
    }
    sort(xl, xl+n);

    ll res = n;
    ll p_reach = xl[0].first + xl[0].second;
    rep1(i, n){
        ll x = xl[i].first;
        ll l = xl[i].second;

        if(x-l < p_reach) {
            --res;

        }
        else p_reach = x+l;
    }
    
    cout << res << endl;

    return 0;
}