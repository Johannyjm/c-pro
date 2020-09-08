#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, d;
    cin >> n >> d;

    ll res = 0;
    for(int i = 0; i < n; ++i){
        ll x, y;
        cin >> x >> y;

        if(x*x + y*y <= d*d) ++res;
    }

    cout << res << endl;
}
