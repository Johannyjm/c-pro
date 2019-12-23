#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll GCD(ll m, ll n){

    if(n==0)return m;
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
    ll n;
    cin >> n;
    ll a[n];
    for (ll i = 0; i < n; ++i) cin >> a[i];

    ll left[n] = {0};
    ll right[n] = {0};

    for(ll i = 1; i < n+1; ++i){
        left[i] = GCD(left[i-1], a[i-1]);
        right[i] = GCD(right[i-1], a[n-i]);
    }

    ll max_gcd = -1;
    for(ll i = 0; i < n; ++i){
        max_gcd = max(max_gcd, GCD(left[i], right[n-i-1]));
    }
    cout << max_gcd << endl;
}