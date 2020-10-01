#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

ll n, a, b;
vector<ll> h;

bool check(ll k){
    vector<ll> h_ = h;
    for(int i = 0; i < n; ++i) h_[i] -= b*k;

    ll diff = a-b;
    ll cnt = 0;
    for(ll e: h_){
        if(e <= 0) continue;
        cnt += (e + diff - 1) / diff;
    }

    return cnt <= k;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> a >> b;
    h.resize(n);
    rep(i, n) cin >> h[i];

    ll ok = 1100000000;
    ll ng = 0;

    while(ok - ng > 1){
        int mid = (ok + ng) / 2;

        if(check(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
    

    return 0;
}