#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, t;
    cin >> n >> t;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll res = t;
    ll prev = a[0] + t;
    rep1(i, n){
        res += t - max(0ll, prev-a[i]);
        prev = a[i] + t;
    }

    cout << res << endl;


    return 0;
}