#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

ll n, k;
vector<ll> a;
bool check(ll lim){
    ll cuts = 0;
    rep(i, n){
        cuts += (a[i]-1)/lim;
        // if(a[i]%2==0) --cuts;
    }

    return cuts <= k;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    a.resize(n);
    rep(i, n) cin >> a[i];

    ll ok = 1000000001;
    ll ng = 0;

    while(abs(ok-ng) > 1){
        ll mid = (ok + ng) / 2;

        if(check(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;

    return 0;
}