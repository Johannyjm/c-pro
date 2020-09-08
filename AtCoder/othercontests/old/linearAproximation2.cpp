#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

ll calc_sadness(ll a[], ll n, ll b){
    ll dist = 0;
    ll i = 1;

    for(int i = 0; i < n; ++i){
        dist += abs(a[i] - (b + i + 1));
    }
    return dist;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    ll a[n], formed[n];
    ll tmp;
    rep(i, n) {
        cin >> tmp;
        a[i] = tmp;
        formed[i] = tmp;
    }

    sort(formed, formed+n);

    ll med = formed[n/2];

    ll res = 1e9;
    for(ll b = med-n/2-10; b < med-n/2+10; ++b){
        res = min(res, calc_sadness(a, n, b));
    }
    cout << res << endl;

}