#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

bool isprime(int num){
    for(int i = 2; i*i <= num; ++i){
        if(num%i == 0) return false;
    }

    return true;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> primes;
    for(int i = 2; i <= 55555; ++i){
        if(isprime(i)){
            if(i%5 == 1) primes.push_back(i);
        }

        if(static_cast<int>(primes.size()) == n) break;
    }

    rep(i, n-1) cout << primes[i] << " ";
    cout << primes.back() << endl;

    return 0;
}