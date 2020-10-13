#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> a(n);
    cin >> a[0];
    ll xo = a[0];
    rep1(i, n){
        cin >> a[i];
        xo ^= a[i];
    }
    // cout << xo << endl;
    rep(i, n-1){
        cout << (a[i]^xo) << " ";
    }
    cout << (a.back()^xo) << endl;



    return 0;
}