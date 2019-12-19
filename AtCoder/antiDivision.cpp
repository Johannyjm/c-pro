#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll m, ll n){
    ll tmp;
    while(m%n != 0){
        tmp = n;
        n = m % n;
        m = tmp;
    }
    return n;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll e = b - a + 1;
    ll f = b/d - (a/d - (a%d==0));
    ll g = b/c - (a/c - (a%c==0));
    ll lcm = d*c/gcd(d,c);
    ll h = b/lcm - (a/lcm - (a%lcm==0));

    cout << e - f - g + h << endl;
}