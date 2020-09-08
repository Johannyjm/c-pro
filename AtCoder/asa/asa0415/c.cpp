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

    int n, x;
    cin >> n >> x;
    vector<int> a(n+1);
    rep(i, n) cin >> a[i];
    
    a[n] = x;
    sort(a.begin(), a.end());
    
    int res = a[1] - a[0];
    rep(i, n){
        res = gcd(res, a[i+1] - a[i]);
    }

    cout << res << endl;

    return 0;
}