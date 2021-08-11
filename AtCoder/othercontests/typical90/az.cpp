#include <iostream>
using namespace std;
using ll = long long;

const ll mod = 1000000007;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    ll res = 1;
    
    for(int i = 0; i < n; ++i){
        ll prod = 0;
        for(int j = 0; j < 6; ++j){
            ll a;
            cin >> a;

            prod = (prod + a) % mod;
        }

        res = (res * prod) % mod;
    }

    cout << res << endl;

    return 0;
}
