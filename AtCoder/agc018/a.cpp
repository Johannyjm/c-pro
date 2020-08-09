#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll m, ll n){
    ll tmp;
    while(m%n){
        tmp = n;
        n = m % n;
        m = tmp;
    }
    return n;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;
    
    ll g;
    cin >> g;
    ll mx = g;
    for(int i = 1; i < n; ++i){
        ll a;
        cin >> a;
        mx = max(mx, a);
        g = gcd(g, a);
    }

    if(k <= mx && k%g == 0) cout << "POSSIBLE" << endl;
    else  cout << "IMPOSSIBLE" << endl;

    return 0;
}
