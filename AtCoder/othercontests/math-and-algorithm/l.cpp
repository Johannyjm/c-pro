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

    auto isprime = [](ll k){
        if(k == 2) return true;
        for(ll l = 2; l * l <= k; ++l){
            if(k % l == 0) return false;
        }
        return true;
    };

    if(isprime(n)) puts("Yes");
    else puts("No");
    

    return 0;
}