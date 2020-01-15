#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

ll gcd(ll m, ll n){
    ll tmp;
    while(m%n){
        tmp = n;
        n = m % n;
        m = tmp;
    }
    return n;
}

ll lcm(ll m, ll n){
    return m / gcd(m, n) * n;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    ll res;
    cin >> n >> res;

    rep1(i, n){
        ll t;
        cin >> t;
        res = lcm(res, t);
    }
    cout << res << endl;
}