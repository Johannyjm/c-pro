#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

ll n;
vector<ll> h, s;
bool check(ll m){
    vector<ll> limit(n);
    rep(i, n) {
        if(h[i] <= m) limit[i] = (m - h[i]) / s[i];
        else return false;
    }
    sort(limit.begin(), limit.end());

    rep(i, n){
        if(limit[i] < i) return false;
    }
    return true;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    h.resize(n);
    s.resize(n);

    rep(i, n) cin >> h[i] >> s[i];

    ll ng = 0;
    ll ok = 10000000000000000;
    while(abs(ok-ng) > 1){
        ll m = (ok + ng) / 2;

        if(check(m)) ok = m;
        else ng = m;
    }

    cout << ok << endl;


    return 0;
}