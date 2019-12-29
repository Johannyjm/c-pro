#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

bool is_prime(ll num){

    for(ll i = 2; i*i <= num; ++i){
        if(num%i==0)return false;
    }
    return true;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll x;
    cin >> x;

    while(1){
        if(is_prime(x)){
            cout << x << endl;
            return 0;
        }
        ++x;
    }
}