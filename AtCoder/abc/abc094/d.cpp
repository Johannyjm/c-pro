#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> a(n);
    
    ll res1 = -1;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        res1 = max(res1, a[i]);
    }

    ll diff = 1001001001;
    ll res2 = -1;
    for(int i = 0; i < n; ++i){
        if(a[i] == res1) continue;
        if(abs(res1 - a[i]*2) < diff){
            diff = abs(res1 - a[i]*2);
            res2 = a[i];
        }
    }

    cout << res1 << " " << res2 << endl;


}
