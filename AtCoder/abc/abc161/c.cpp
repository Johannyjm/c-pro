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

    ll n, k;
    cin >> n >> k;

    if(n <= k){
        cout << min(n, k-n) << endl;
        return 0;
    }

    // if(n == k*2) cout << 0 << endl;
    // if(n < k*2) cout << n-k << endl;
    // cout << gcd(n, k) << endl;

    cout << min(n%k, k-(n%k)) << endl;


    return 0;
}