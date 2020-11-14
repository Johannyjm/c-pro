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

    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    if(n==2){
        cout << max(a[0], a[1]) << endl;
        return 0;
    }

    ll mn_gcd1 = 1001001001;
    ll mn_idx1 = -1;
    for(int i = 1; i < n; ++i){
        ll g = gcd(a[0], a[i]);

        if(g < mn_gcd1){
            mn_gcd1 = g;
            mn_idx1 = i;
        }
    }

    ll mn_gcd2 = gcd(a[0], a[1]);
    ll mn_idx2 = 0;
    for(int i = 2; i < n; ++i){
        ll g = gcd(a[1], a[i]);

        if(g < mn_gcd2){
            mn_gcd2 = g;
            mn_idx2 = i;
        }
    }

    ll g1 = 0;
    rep(i, n){
        if(i == mn_idx1) continue;
        g1 = gcd(g1, a[i]);
    }

    ll g2 = 0;
    rep(i, n){
        if(i == mn_idx2) continue;
        g2 = gcd(g2, a[i]);
    }

    ll g3 = 0;
    rep(i, n){
        if(i == 0) continue;
        g3 = gcd(g3, a[i]);
    }

    ll g4 = 0;
    rep(i, n){
        if(i == 1) continue;
        g4 = gcd(g4, a[i]);
    }

    cout << mn_idx1 << " " << mn_idx2 << " " << g1 << " " << g2 << " " << g3 << " " << g4 << endl;
    cout << max(g1, g2) << endl;
    

    return 0;
}