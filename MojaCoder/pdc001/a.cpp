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

int a, b;
bool valid(int n){
    map<ll, ll> primes = prime_factor(n).first;
    int num_div = 1;
    for(auto k: primes){
        num_div *= k.second + 1;
    }

    if(n%2 == 1){
        return num_div == a;
    }
    else{
        return num_div == b;
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n >> a >> b;

    int res = 0;
    rep1(i, n+1){
        if(valid(i)) ++res;
    }

    cout << res << endl;

    return 0;
}