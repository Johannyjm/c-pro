#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

pair<map<ll, ll>, set<ll>> prime_factor(ll n){
    map<ll, ll> res;
    set<ll> primes;
    for(ll i = 2; i*i <= n; ++i) {
        if(n%i==0) primes.insert(i);

        while(n%i == 0){
            ++res[i];
            n /= i;
        }
    }
    if(n != 1) {
        res[n] = 1;
        primes.insert(n);
    }
    return make_pair(res, primes);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    if(n <= 9){
        cout << 0 << endl;
        return 0;
    }

    map<ll, ll> primes;
    for(ll i = 2; i <= n; ++i){
        pair<map<ll, ll>, set<ll>> out = prime_factor(i);
        
        for(auto k: out.first){
            primes[k.first] += k.second;
        }
    }

    vector<int> ex;
    for(auto k: primes) ex.push_back(k.second);
    
    ll m = ex.size();
    ll res = 0;
    rep(i, m){
        rep(j, m){            
            rep(k, m){

                if(!(i<j && j<k)) continue;
                
                for(int ii = 1; ii <= ex[i]; ++ii){
                    for(int jj = 1; jj <= ex[j]; ++jj){
                        for(int kk = 1; kk <= ex[k]; ++kk){
                            if((ii+1)*(jj+1)*(kk+1) == 75) ++res;
                        }
                    }
                }
            }

            if(!(i < j)) continue;
            
            for(int ii = 1; ii <= ex[i]; ++ii){
                for(int jj = 1; jj <= ex[j]; ++jj){
                    if((ii+1)*(jj+1) == 75) ++res;
                }
            }
        }

        if(ex[i] >= 74) ++res;
    }    

    cout << res << endl;

    return 0;
}