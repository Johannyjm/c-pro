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
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    sort(a.begin(), a.end(), greater<ll>());

    vector<ll> sm(n, 0);
    sm.back() = -a.back();
    for(int i = n-2; i > 0; --i){
        sm[i] = sm[i+1] - a[i];
    }

    ll res = 0;
    rep(i, n-1){
        res += a[i]*(n-i-1) + sm[i+1];
    }

    cout << res << endl;

    return 0;
}