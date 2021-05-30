#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;

    map<ll, ll> mp;
    rep(i, n){
        ll a, b;
        cin >> a >> b;
        mp[a] += b;
    }

    ll now = 0;
    for(auto key: mp){
        ll nxt = key.first;
        // cout << nxt << " " << now << endl;
        if(nxt - now <= k){
            k -= nxt - now;
            k += key.second;
            now = nxt;
        }
        else{
            cout << now + k << endl;
            return 0;
        }
    }

    cout << now + k << endl;

    return 0;
}