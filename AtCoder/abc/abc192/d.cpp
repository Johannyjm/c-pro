#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 9223372036854775807ll;

ll basen(string x, ll d){
    ll ret = 0;
    ll base = 1;
    ll n = x.size();

    for(ll i = n-1; i >= 0; --i){
        ret += (x[i]-'0') * base;
        base *= d;
        if(base < 0) return -1;
    }

    return ret;
}


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string x;
    ll m;
    cin >> x >> m;

    ll d = 0;
    for(auto c: x){
        d = max(d, ll(c-'0'));
    }

    if(basen(x, d+1)==-1 || basen(x, d+1)>m){
        cout << 0 << endl;
        return 0;
    }

    ll ok = d+1;
    ll ng = INF - ok;
    while(ng-ok > 1){
        ll mid = (ok + ng) / 2;

        ll val = basen(x, mid);

        cout << ok << " " << mid << " " << ng << " " << val << endl;
        if(val==-1 || val>m) ng = mid;
        else ok = mid;
    }

    cout << ok - d << endl;

    return 0;
}
