#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, C;
    cin >> n >> C;

    vector<ll> a(n), b(n), c(n);
    vector<pair<ll, ll>> ab;
    rep(i, n){
        cin >> a[i] >> b[i] >> c[i];

        ab.push_back({a[i], c[i]});
        ab.push_back({b[i]+1, -c[i]});
    }

    sort(ab.begin(), ab.end());

    ll prev = ab[0].first;
    ll total = ab[0].second;
    ll res = 0;
    rep1(i, 2*n){
        ll curr = ab[i].first;
        ll dif = ab[i].second;
        ll seg = curr - prev;

        res += seg * min(total, C);
        total += dif;

        prev = curr;
    }

    cout << res << endl;

    return 0;
}