#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, h;
    cin >> n >> h;

    vector<ll> a(n), b(n);

    ll a_mx = -1;
    rep(i, n){
        cin >> a[i] >> b[i];
        a_mx = max(a_mx, a[i]);
    }

    sort(b.begin(), b.end(), greater<ll>());

    ll res = 0;
    rep(i, n){
        if(b[i] < a_mx) break;
        h -= b[i];
        ++res;
        if(h <= 0){
            cout << res << endl;
            return 0;
        }
    }

    cout << res + (h + a_mx - 1) / a_mx << endl;



    return 0;
}