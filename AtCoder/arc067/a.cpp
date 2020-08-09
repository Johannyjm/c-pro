#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    
    map<ll, ll> factors;
    for(ll i = 2; i <= n; ++i){
        ll tmp = i;
        for(ll j = 2; j * j <= i; ++j){
            while(tmp%j == 0){
                ++factors[j];
                tmp /= j;
            }
        }
        if(tmp != 1) ++factors[tmp];
    }

    ll res = 1;
    for(auto elem: factors){
        res = res * ((elem.second+1) % mod) % mod;
    }

    cout << res << endl;
}
