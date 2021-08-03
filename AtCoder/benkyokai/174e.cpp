#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int n, k;
vector<ll> a;
bool check(ll mid){
    ll cnt = 0;
    for(int i = 0; i < n; ++i){
        cnt += a[i] / mid;
        if(a[i] % mid == 0) --cnt;
    }

    return cnt <= k;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    a.resize(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    ll ok = 1100000000;
    ll ng = 0;

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
