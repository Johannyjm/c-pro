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
    vector<ll> s(n);
    rep(i, n){
        cin >> s[i];
        if(s[i] == 0){
            cout << n << endl;
            return 0;
        }
    }
    if(k == 0){
        cout << 0 << endl;
        return 0;
    }

    ll r = 0;
    ll mul = s[0];
    ll res = 0;
    for(ll l = 0; l < n; ++l){
        if(l > 0) mul /= s[l-1];

        while(r < n && mul <= k){
            ++r;
            mul *= s[r];
        }

        res = max(res, r-l);
    }

    cout << res << endl;

    return 0;
}