#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll k;
    cin >> k;
    vector<ll> a(k);
    rep(i, k) cin >> a[i];

    reverse(a.begin(), a.end());

    if(a.front() != 2){
        cout << -1 << endl;
        return 0;
    }

    ll mn_pre = 2;
    ll mx_pre = 2;
    rep(i, k){
        ll mn_cur = (mn_pre+a[i]-1)/a[i] * a[i];
        ll mx_cur = (mx_pre / a[i]) * a[i] + a[i] - 1;

        // cout << a[i] << " " << mn_cur << " " << mx_cur << endl;
        ll a_ = a[i] * ((mn_cur + a[i] - 1) / a[i]);
        if(mn_cur > a_ || mx_cur < a_){
            cout << -1 << endl;
            return 0;
        }



        mn_pre = mn_cur;
        mx_pre = mx_cur;
    }

    cout << mn_pre << " " << mx_pre << endl;

    return 0;
}