#include <iostream>
typedef long long ll;
using namespace std;


ll mod_mul(ll x, ll y, ll m){
    return (x%m * y%m) % m;
}

ll mod_pow(ll x, ll y, ll m){
    if(y == 0) return 1;
    else if(y == 1) return x%m;
    else if(y%2 == 0){
        ll t = mod_pow(x, y/2, m) % m;
        return mod_mul(t, t, m);
    }
    else{
        ll t = mod_pow(x, y/2, m) % m;
        ll k = mod_mul(t, t, m);
        return mod_mul(k, x, m);
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m, p;
    cin >> n >> m >> p;

    cout << mod_pow(n, p, m) << endl;

    return 0;
}
