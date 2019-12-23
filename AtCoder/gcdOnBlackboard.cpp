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
    ll a, prev;
    cin >> prev;
    ll gcds[n-1];
    ll gcd_min = 1e9;

    for(ll i = 0; i < n-1; ++i){
        cin >> a;
        gcds[i] = GCD(prev, a);
        gcd_min = min(gcd_min, gcds[i]);
        prev = a;
    }
    for(int i = 0; i < n-1; ++i) cout << gcds[i] << endl;
    cout << gcd_min << endl;

}