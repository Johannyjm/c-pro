#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    vector<ll> a(n+1);
    ll sm = 0;
    rep(i, n+1){
        cin >> a[i];
        sm += a[i];
    }

    if(n==0){
        if(a[0]==1) cout << 1 << endl;
        else cout << -1 << endl;
        return 0;
    }

    ll res = 0;
    ll curr = 1;
    rep(i, n){
        if(curr <= a[i]) {
            cout << -1 << endl;
            return 0;
        }
        res += curr;
        sm -= a[i];
        ll nxt = min(sm, (curr - a[i]) * 2);
        // cout << i << " " << curr << " " << nxt << " " << sm << endl;
        curr = nxt;
        
    }
    if(curr != sm){
        cout << -1 << endl;
        return 0;
    }
    res += curr;

    cout << res << endl;

    return 0;
}