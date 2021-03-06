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

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll k;
    cin >> k;

    ll res = 0;
    rep1(i, k+1){
        rep1(j, k+1){
            rep1(l, k+1){
                res += gcd(i, gcd(j, l));
            }
        }
    }

    cout << res << endl;


    return 0;
}