#include <iostream>
#include <map>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n, k;
    cin >> n >> k;
    
    map<ll, ll> mp;
    for(int i = 0; i < n; ++i){
        ll a, b;
        cin >> a >> b;
        mp[a] += b;
    }

    ll now = 0;
    for(auto key: mp){
        now += key.second;
        if(now >= k){
            cout << key.first << endl;
            return 0;
        }
    }

    return 0;
}
