#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

map<ll, ll> bitcnt(ll num){
    map<ll, ll> ret;
    ll base = 1;
    while(base <= num) base *= 2;
    base /= 2;

    if(base == num){
        ret[base] = 1;
        const ll b = base/2;
        while(base){
            base /= 2;
            ret[base] = b;
        }
        return ret;
    }
    
    while(base){
        ret[base] = num/(base*2)*base;
        if(num%(base*2) >= base) ret[base] += num%(base*2) - base + 1;
        base /= 2;
    }

    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll a, b;
    cin >> a >> b;
    
    map<ll, ll> cnt_a, cnt_b;
    cnt_a = bitcnt(a-1);
    cnt_b = bitcnt(b);

    ll res = 0;
    for(ll i = 0; i < 60; ++i){
        ll base = 1ll << i;
        if((cnt_b[base] - cnt_a[base])%2 == 1) res += base;
    }

    cout << res << endl;

}
