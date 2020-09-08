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

bool is_prime(ll n){
    if(n == 1) return false;

    for (int i = 2; i * i <= n; ++i){
        if(n%i == 0) return false;
    }
    return true;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll a, b;
    cin >> a >> b;

    int res = 0;
    rep1(i, gcd(a, b) + 1){
        if((a%i==0 && b%i==0) && (i == 1 || is_prime(i))) ++res;
    }
    cout << res << endl;

}