#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

bool isprime(ll x){
    for(int i = 2; i*i <= x; ++i){
        if(x%i == 0) return false;
    }
    return true;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll x;
    cin >> x;

    while(1){
        if(isprime(x)){
            cout << x << endl;
            return 0;
        }
        ++x;
    }

    return 0;
}