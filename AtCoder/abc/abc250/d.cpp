#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

bool is_prime(ll n){
    if(n == 1) return false;
    
    for(ll i = 2; i*i <= n; ++i){
        if(n%i == 0) return false;
    }

    return true;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<ll> primes;
    rep1(i, 100000){
        if(is_prime(i)){
            primes.push_back(i);
        }
    }
    // cout << primes[56] << endl;
    // cout << primes[62687] << endl;

    ll n;
    cin >> n;

    ll res = 0;    
    for(int i = 0; i < (int)primes.size()-1; ++i){
        
        if(primes[i] * primes[i+1]*primes[i+1]*primes[i+1] > n) break;
        ll p = primes[i];
        int ok = i;
        int ng = primes.size();

        // if(i < 100) cout << i << " " << p << " " << ok << " " << ng << endl;

        while(ng - ok > 1){
            int mid = (ok + ng) / 2;
            // if(i == 56){
            //     cout << ok << " " << mid << " " << ng << endl;
            // }

            ll q = primes[mid];

            if(p*q*q*q <= n) ok = mid;
            else ng = mid;           
        }

        // if(i < 100){
        //     cout << ok << endl;
        //     cout << endl;
        // }


        res += ok - i;

    }

    cout << res << endl;

    return 0;
}