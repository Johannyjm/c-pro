#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    ll res = 0;
    for(int i = 0; i < n-1; ++i){
        if(a[i] >= x){
            res += a[i] - x;
            res += a[i+1];
            a[i] = x;
            a[i+1] = 0;
        }
        else{
            if(a[i] + a[i+1] > x){
                res += a[i+1] - (x-a[i]);
                a[i+1] = x - a[i];
            }
        }
    }

    cout << res << endl;
}
