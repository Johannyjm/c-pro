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

    ll a, b;
    cin >> a >> b;
    ll lcm = a*b/gcd(a, b);

    cout << lcm << endl;
}