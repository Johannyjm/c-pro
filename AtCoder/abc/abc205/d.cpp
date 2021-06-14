#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<pair<ll, ll>> ki(q);
    rep(i, q){
        ll k;
        cin >> k;
        ki[i] = {k, i};
    }

    sort(ki.begin(), ki.end());

    vector<ll> res(q);
    ll ptr = 0;
    ll now = 0;
    ll prev = 0;
    rep(i, n){
        now += a[i] - prev - 1;
        while(ptr < q && now >= ki[ptr].first){
            res[ki[ptr].second] = ki[ptr].first + i;
            ++ptr;
        }
        prev = a[i];
    }

    while(ptr < q){
        res[ki[ptr].second] = ki[ptr].first + n;
        ++ptr;
    }

    rep(i, q) cout << res[i] << endl;

    return 0;
}