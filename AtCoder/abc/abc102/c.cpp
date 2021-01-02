#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int n;
vector<ll> a;
ll calc(ll b){
    ll ret = 0;
    rep(i, n){
        ret += abs(a[i] - (b + i+1));
    }
    return ret;
}


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

cin >> n;
    a.resize(n);
    rep(i, n) cin >> a[i];

    ll l = -100000000;
    ll r = 1100000000;

    ll mn_dist = r-l;
    while(1){
        // cout << l << " " << r << endl;
        ll c1 = (l*2 + r) / 3;
        ll c2 = (l + r*2) / 3;

        if(calc(c1) > calc(c2)) l = c1;
        else r = c2;

        if(r-l >= mn_dist) break;
        else mn_dist = r-l;
    }

    // cout << l << " " << r << " " << calc((l*2 + r)/3) << " " << calc((l+r*2)/3) << endl;
    cout << min(calc((l*2 + r) / 3), calc((l + r*2) / 3)) << endl;


    return 0;
}