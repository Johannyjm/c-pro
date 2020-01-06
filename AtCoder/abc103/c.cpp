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

ll f(ll m, ll a[], ll n){
    ll ret = 0;
    rep(i, n) ret += m % a[i];
    
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    ll a[n];
    rep(i, n) cin >> a[i];

    ll m = a[0];
    rep1(i, n) m = lcm(m, a[i]);
    --m;

    cout << f(m, a, n) << endl;
}