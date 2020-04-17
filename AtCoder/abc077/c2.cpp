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
        int r = n-1;
        ll upper;
        if(a[r] < mid) upper = n;
        else if(a[l] > mid) continue;
        else{
            int m;
            while(abs(r-l) > 1){
                
                m = (l + r) / 2;

                if(a[m] < mid) l = m;
                else r = m;
            }
            if(a[m] < mid) upper = m+1;
            else upper = m;
        }
        // cout << upper << endl;

        l = 0;
        r = n-1;
        ll lower;
        if(c[l] > mid) lower = n;
        else if(c[r] < mid) continue;
        else{
            int m;
            while(abs(r-l) > 1){

                m = (l + r) / 2;

                if(c[m] <= mid) l = m;
                else r = m;
            }
            if(c[m] < mid) lower = n - m - 1;
            else lower = n - m;
            // cout << lower << endl;
        }

        res += upper * lower;

    }

    cout << res << endl;

    return 0;
}