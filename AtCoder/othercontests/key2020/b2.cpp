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

    pair<ll, ll> xi[n];
    pair<ll, ll> lr[n];
    pair<ll, ll> rl[n];

    rep(i, n) {
        ll x, l;
        cin >> x >> l;

        xi[i] = make_pair(x, i);
        lr[i] = make_pair(x-l, x+l);
        rl[i] = make_pair(x+l, x-l);
    }
    sort(xi, xi+n);
    sort(lr, lr+n);
    sort(rl, rl+n);

    rep(i, n){
        
    }




    return 0;
}