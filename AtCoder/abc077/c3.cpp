#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    vector<ll> a(n), b(n), c(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    ll res = 0;
    rep(i, n){
        ll mid = b[i];
        int l = 0;
        int r = n;
        
        while(l < r){
            int m = (l + r) / 2;
            
            if(a[m] < mid) l = m+1;
            else r = m;
        }
        ll upper = l;

        l = 0;
        r = n;
        while(l < r){
            int m = (l + r) / 2;

            if(mid < c[m]) r = m;
            else l = m+1;
        }
        ll lower = n - l;
        
        res += upper * lower;
    }

    cout << res << endl;

    return 0;
}