#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    map<ll, ll> imos;
    rep(i, n){
        ll a, b;
        cin >> a >> b;
        imos[a] += 1;
        imos[a+b] -= 1;
    }

    vector<ll> res(n+1, 0);
    ll now = 0;
    ll prev = 0;

    for(auto k: imos){
        // cout << k.first << " " << k.second << endl;
        ll range = k.first - prev;
        prev = k.first;

        if(now != 0) res[now] += range;

        now += k.second;

        
    }

    rep1(i, n) cout << res[i] << " ";
    cout << res[n] << endl;

    return 0;
}