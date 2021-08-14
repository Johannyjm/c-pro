#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n, q;
    cin >> n >> q;

    vector<ll> a(n), diff(n-1);
    ll now = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if(i > 0){
            diff[i-1] = a[i] - a[i-1];
            now += abs(a[i] - a[i-1]);
        }
    }

    while(q--){
        ll l, r, v;
        cin >> l >> r >> v;
        --l;
        --r;

        ll lbefore, lafter, rbefore, rafter;
        ll dl = 0;
        ll dr = 0;
        if(l > 0){
            lbefore = diff[l-1];
            lafter = lbefore + v;
            dl = abs(lafter) - abs(lbefore);
        }

        if(r < n-1){
            rbefore = diff[r];
            rafter = rbefore - v;
            dr = abs(rafter) - abs(rbefore);
        }

        now += dl + dr;
        cout << now << "\n";
        if(l > 0) diff[l-1] = lafter;
        if(r < n-1) diff[r] = rafter;
    }


    return 0;
}
