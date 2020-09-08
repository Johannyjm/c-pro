#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll GCD(ll m, ll n){
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
    cin >> a[0];
    ll gcd_min = 1e10;
    ll gcd_min_idx = -1;

    for (ll i = 1; i < n; ++i){
        cin >> a[i];
        ll gcd_current = GCD(a[0], a[i]);
        if(gcd_min > gcd_current){
            gcd_min = gcd_current;
            gcd_min_idx = i;
        }
    }
    ll gcd1 = a[0];
    for(ll i = 1; i < n; ++i){
        if(i == gcd_min_idx)continue;
        gcd1 = GCD(gcd1, a[i]);
    }

    ll gcd2 = a[1];
    for(ll i = 2; i < n; ++i){
        gcd2 = GCD(gcd2, a[i]);
    }

    ll gcd_min2 = 1e10;
    ll gcd_min_idx2 = -1;

    for (ll i = 0; i < n-1; ++i){
        ll gcd_current = GCD(a[n-1], a[i]);
        if(gcd_min2 > gcd_current){
            gcd_min2 = gcd_current;
            gcd_min_idx2 = i;
        }
    }
    ll gcd3 = a[n-1];
    for(ll i = 0; i < n-1; ++i){
        if(i == gcd_min_idx2)continue;
        gcd3 = GCD(gcd3, a[i]);
    }

    ll gcd4 = a[0];
    for(ll i = 1; i < n-1; ++i){
        gcd4 = GCD(gcd4, a[i]);
    }

    cout << max(max(gcd1, gcd2), max(gcd3, gcd4)) << endl;
}