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
    ll a[n];

    rep(i, n) cin >> a[i];

    ll l = -1e9;
    ll r = 1e9;
    ll res = 1e20;

    while(abs(l-r)>2){
        ll m1 = (2*l + r) / 3;
        ll m2 = (l + 2*r) / 3;

        ll dist1 = calc_sadness(a, n, m1);
        ll dist2 = calc_sadness(a, n, m2);

        res = min(res, min(dist1, dist2));

        if(dist1 <= dist2){
            r = m2;
        }
        else{
            l = m1;
        }
    }

 
    cout << res << endl;


}