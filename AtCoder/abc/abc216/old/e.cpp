#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll allsum = 0;
    rep(i, n){
        cin >> a[i];
        allsum += a[i];
    }
    if(allsum <= k){
        ll res = 0;
        rep(i, n) res += (1+a[i]) * a[i] / 2;
        cout << res << endl;
        return 0;
    }
    if(n == 1){
        ll res = (a[0]-k+1 + a[0]) * k / 2;
        cout << res << endl;
        return 0;
    }

    sort(a.begin(), a.end(), greater<ll>());

    ll res = 0;
    ll cnt = 1;
    rep1(i, n){
        ll diff = a[i-1] - a[i];
        if(cnt*diff <= k){
            res += ((a[i]+1 + a[i-1]) * diff / 2) * cnt;
            k -= diff*cnt;
            if(k == 0) break;
        }
        else{
            ll whole = k / cnt;
            ll rest = k % cnt;
            // cout << whole << " " << rest << endl;
            res += ((a[i-1]-whole+1 + a[i-1]) * whole / 2) * cnt;
            res += (a[i-1]-whole)*rest;

            cout << res << endl;
            return 0;
        }
        ++cnt;
    }

    if(k > 0){
        ll whole = k / cnt;
        ll rest = k % cnt;
        res += ((a.back()-whole+1 + a.back()) * whole / 2) * cnt;
        res += (a.back() - whole) * rest;
    }

    cout << res << endl;

    return 0;
}