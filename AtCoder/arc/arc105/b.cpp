#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
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

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> a(n);
    ll mx = 0;
    ll mn = 1001001001;
    rep(i, n){
        cin >> a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }

    // rep(i, n){
    //     a[i] = gcd(mn, a[i]);
    //     mn = min(mn, a[i]);
    //     cout << a[i] << " ";
    // }

    // cout << endl;
    // return 0;

    // cout << mx << " " << mn << endl;

    while(mx != mn){

        ll mnn = mn;
        ll mxx = 0;
        rep(i, n){
            a[i] = gcd(mn, a[i]);
            // cout << a[i] << endl;
            mnn = min(mnn, a[i]);
            mxx = max(mxx, a[i]);
        }
        mn = mnn;
        mx = mxx;

        // cout << mx << " " << mn << endl;
    }

    cout << mn << endl;

    return 0;
}