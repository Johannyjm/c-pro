#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll proc(ll n){
    ll n10 = 0;
    ll base = 1;

    // 8base to 10base;
    while(n){
        n10 += base * (n%10);
        n /= 10;
        base *= 8;
    }

    vector<ll> n9v;

    // 10base to 9 base;
    while(n10){
        n9v.push_back(n10%9);
        n10 /= 9;
    }

    ll ret = 0;
    base = 1;
    for(auto e: n9v){
        if(e == 8) e = 5;
        ret += e * base;
        base *= 10;
    }

    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;
    
    while(k--){
        n = proc(n);
    }
    
    cout << n << endl;

    return 0;
}
