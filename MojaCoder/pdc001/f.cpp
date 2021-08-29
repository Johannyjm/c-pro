#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

bool is_prime(int n){
    if(n == 1) return false;
    
    for(int i = 2; i*i <= n; ++i){
        if(n%i == 0) return false;
    }

    return true;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<ll> primes;
    rep1(i, 10000000){
        if(is_prime(i)) primes.push_back(i);
    }

    ll a, b;
    cin >> a >> b;

    ll res = 0;
    for(ll prime: primes){
        ll base = 1;
        while(1){
            ll num = pow(prime, base);
            if(a <= num && num <= b){
                res = max(res, base);
            }
            ++base;
            if(num > b) break;
        }
    }

    cout << res << endl;
    

    return 0;
}