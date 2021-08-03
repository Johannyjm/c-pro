#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

ll n, k;
vector<ll> a, f;
bool check(ll mid){
    ll cnt = 0;
    for(int i = 0; i < n; ++i){
        if(a[i]*f[i] <= mid) continue;
        // cout << a[i] - (mid + f[i] - 1) / f[i] << " " << a[i] << " " << f[i] << endl;
        cnt += a[i] - mid / f[i];
    }

    return cnt <= k;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    a.resize(n);
    f.resize(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> f[i];
    
    sort(a.begin(), a.end());//, greater<ll>());
    sort(f.begin(), f.end(), greater<ll>());

    ll ok = 1ll << 60;
    ll ng = -1;

    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;

        if(check(mid)){
            ok = mid;
        }
        else{
            ng = mid;
        }
    }

    cout << ok << endl;

    return 0;
}
