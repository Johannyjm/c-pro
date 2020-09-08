#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll r = 0;
    ll sm = a[0];
    ll res = 0;
    for(ll l = 0; l < n; ++l){
        if(l > 0) sm -= a[l-1];
        while(r < n &&sm < k){
            ++r;
            sm += a[r];
        }
        res += n-r;
    }

    cout << res << endl;

    return 0;
}