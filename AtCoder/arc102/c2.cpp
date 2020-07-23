#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;

    if(k%2==1){
        ll base = n/k;
        ll res = pow(base, 3);
        cout << res << endl;
    }
    else{
        ll odd_base = 1 + (n-(k/2))/k;
        if(n*2 < k) odd_base = 0;
        ll res = pow(odd_base, 3);

        ll even_base = n/k;
        res += pow(even_base, 3);

        cout << res << endl;
    }
    return 0;
}
