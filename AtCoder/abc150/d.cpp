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

    ll n, m;
    cin >> n >> m;

    ll LCM;
    cin >> LCM;

    rep1(i, n){
        ll a;
        cin >> a;
        LCM = lcm(LCM, a);

        if(LCM > 2*m){
            cout << 0 << endl;
            return 0;
        }
    }

    int d = 0;
    if(LCM/2 + (m/LCM+1 -1)*LCM == m) ++d;

    cout << m/LCM + 1 + d << endl;
}