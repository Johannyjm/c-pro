#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, t;
    cin >> n >> t;

    vector<ll> a(n);

    ll mn_val = 1001001001;
    ll mx_range = 0;
    bool flg = false;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        
        if(a[i] < mn_val){
            mn_val = a[i];
            flg = true;
        }

        else if(flg){
            mx_range = max(mx_range, a[i]-mn_val);
        }
    }

    // ll gain = t/2*mx_range;
    // cout << gain << endl;

    mn_val = 1001001001;
    ll res = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] < mn_val){
            mn_val = a[i];
            flg = true;
        }

        else if(flg){
            if(a[i]-mn_val == mx_range) ++res;
        }
    }

    cout << res << endl;

    return 0;
}
