#include <iostream>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;

    ll res = 0;
    if(m >= 2*n){
        res += n;
        m -= 2*n;
    }
    else{
        res += m/2;
        n -= m;
        m -= m/2 * 2;
    }

    res += m/4;

    cout << res << endl;

    return 0;
}
