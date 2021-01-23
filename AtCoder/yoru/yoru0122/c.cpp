#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

ll gcd(ll m, ll n){
    ll tmp;
    while(m%n){
        tmp = n;
        n = m % n;
        m = tmp;
    }
    return n;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, x;
    cin >> n >> x;

    ll g = 0;
    rep(i, n){
        ll xi;
        cin >> xi;

        g = gcd(g, abs(x - xi));
    }

    cout << g << endl;

    return 0;
}