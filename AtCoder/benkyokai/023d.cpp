#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int n;
vector<ll> h, s;
bool check(ll mid){
    vector<ll> limit(n);
    for(int i = 0; i < n; ++i){
        if(h[i] > mid) return false;
        else limit[i] = (mid - h[i]) / s[i];
    }
    
    sort(limit.begin(), limit.end());

    for(int i = 0; i < n; ++i){
        if(limit[i] < i) return false;
    }
    return true;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    
    h.resize(n);
    s.resize(n);
    for(int i = 0; i < n; ++i) cin >> h[i] >> s[i];

    ll ok = 1ll << 60;
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
