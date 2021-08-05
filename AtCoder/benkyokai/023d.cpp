#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int n;
vector<ll> h, s;
bool check(ll mid){
    
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

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
