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
    vector<ll> sm(n+1, 0);
    rep(i, n){
        cin >> a[i];
        sm[i+1] = sm[i] + a[i];
    }

    ll r = 0;
    ll res = 0;
    for(ll l = 0; l < n; ++l){
        while(sm[r+1] - sm[l] < k){
            ++r;
            if(r > n-1) break;
        }
        if(sm[r+1] - sm[l] >= k) {
            res += n-r;
            cout << l << " " << r << "~ : " << n-r << endl;
        }
    }

    cout << res << endl;

    return 0;
}