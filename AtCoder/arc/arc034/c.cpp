#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

const int mod = 1000000007;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll a, b;
    cin >> a >> b;
    
    map<ll, ll> pfs;
    for(ll i = b+1; i <= a; ++i){
        ll n = i;
        for(ll j = 2; j*j <= i; ++j){
            while(n%j == 0){
                ++pfs[j];
                n /= j;
            }
        }
        if(n != 1) ++pfs[n];
    }

    ll res = 1;
    for(auto elem: pfs){
        res = (res * (elem.second + 1)) % mod;
    }

    cout << res << endl;

    return 0;
}
