#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    map<ll, ll> res;
    auto isprime = [](ll k){
        if(k == 2) return true;
        for(ll l = 2; l*l <= k; ++l){
            if(k%l == 0) return false;
        }
        return true;
    };
    
    for(ll k = 2; k*k <= n; ++k){
        if(!isprime(k)) continue;
        if(n%k != 0) continue;

        ll idx = 0;
        while(n%k == 0){
            n /= k;
            ++idx;
        }

        res[k] = idx;
        if(n != 1) res[n] = 1;
    }

    for(auto k: res){
        rep(_, k.second) cout << k.first << " ";
    }
    cout << endl;

    return 0;
}