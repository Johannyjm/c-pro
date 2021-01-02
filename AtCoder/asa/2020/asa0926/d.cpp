#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll res = 0;
    rep(i, n-1){
        if(a[i]+a[i+1] > x){
            if(a[i] > x){
                res += a[i+1] + a[i] - x;
                a[i] = x;
                a[i+1] = 0;
            }
            else{
                res += a[i+1] - (x-a[i]);
                a[i+1] = x - a[i];
            }
        }
    }

    cout << res << endl;

    return 0;
}