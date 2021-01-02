#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll res = 0;

    if(n==1){
        res = a[0]/2;
    }

    rep(i, n-1){
        if(a[i]%2){
            if(a[i+1]%2){
                res += (a[i]+a[i+1])/2;
                a[i+1] = 0;
            }
            else if(a[i+1]==0){
                res += a[i]/2;
            }
            else {
                res += (a[i]+a[i+1])/2;
                a[i+1] = 1;
            }
        }
        else res += a[i]/2;
    }

    cout << res << endl;

    return 0;
}