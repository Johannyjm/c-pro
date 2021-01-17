#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    vector<ll> res(n), mx(n);
    mx[0] = a[0];
    rep1(i, n){
        mx[i] = max(mx[i-1], a[i]);
    }

    ll now = a[0] * b[0];
    res[0] = now;
    rep1(i, n){
        now = max(now, mx[i]*b[i]);
        res[i] = now;
    }

    for(auto e: res) cout << e << endl;
    

    return 0;
}