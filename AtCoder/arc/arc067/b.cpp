#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, a, b;
    cin >> n >> a >> b;

    vector<ll> x(n);
    for(int i = 0; i < n; ++i) cin >> x[i];
    
    ll prev = x[0];
    ll res = 0;
    for(int i = 1; i < n; ++i){
        ll curr = x[i];
        ll dist = curr - prev;
        res += min(dist*a, b);

        prev = curr;
    }
    
    cout << res << endl;

    return 0;
}
