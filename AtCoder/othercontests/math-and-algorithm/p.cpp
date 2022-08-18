#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

ll gcd(ll x, ll y){
    if(x == 0) return y;
    return gcd(y%x, x);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    ll g = 0;
    rep(i, n){
        ll a;
        cin >> a;

        g = gcd(g, a);
    }

    cout << g << endl;

    return 0;
}