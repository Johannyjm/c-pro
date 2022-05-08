#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

ll func(ll a, ll b){
    return a*a*a + a*a*b + a*b*b + b*b*b;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n;
    cin >> n;

    if(n == 0){
        cout << 0 << endl;
        return 0;
    }

    vector<ll> cand;
    for(ll a = 0; a <= 1000000; ++a){
        ll ok = 1000000;
        ll ng = -1;

        while(ok - ng > 1){
            ll mid = (ok + ng) / 2;

            if(func(a, mid) >= n) ok = mid;
            else ng = mid;
        }
        cand.push_back(func(a, ok));
    }

    ll res = 1ll << 60;
    for(auto elem: cand) res = min(res, elem);

    cout << res << endl;

    return 0;
}