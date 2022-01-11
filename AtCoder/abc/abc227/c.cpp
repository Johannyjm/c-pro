#include <iostream>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    ll res = 0;
    for(ll a = 1; a*a*a <= n; ++a){
        for(ll b = a; a*b*b <= n; ++b){
            res += max(0ll, n / (a*b) - b + 1);
        }
    }

    cout << res << endl;

    return 0;
}
