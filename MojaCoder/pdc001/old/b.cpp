#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

unordered_map<ll, ll> mp;
unordered_set<ll> seen, must;
void prime_factor(ll n){
    unordered_map<ll, ll> res;
    for(ll i = 2; i*i <= n; ++i) {

        while(n%i == 0){
            ++res[i];
            n /= i;
        }
        if(seen.count(i)) mp[i] = min(mp[i], res[i]);
        else{
            mp[i] = res[i];
            seen.insert(i);
        }
    }
    if(n != 1) {
        res[n] = 1;
        if(mp[n] == 0) mp[n] = res[n];
        else mp[n] = min(mp[n], res[n]);
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    rep(i, n){
        prime_factor(a[i]);
    }

    ll res = 1;
    for(auto k: mp){
        res *= k.second + 1;
        cout << k.first << " " << k.second << endl;
    }

    cout << res << endl;

    return 0;
}