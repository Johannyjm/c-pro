#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n;
    cin >> n;
    ll a[n+1], b[n];
    for(ll i = 0; i < n+1; ++i) cin >> a[i];

    ll res = 0;
    ll prev = a[0];
    ll zero = 0;
    for(ll i = 0; i < n; ++i){
        ll b;
        cin >> b;

        if(prev >= b){
            res += b;
            prev = a[i+1];
        }
        else {
            res += min(prev+a[i+1], b);
            prev = max(prev+a[i+1]-b, zero);
        }
    }
    cout << res << endl;
}